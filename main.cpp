//include "godeye_lip.h"
 
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <malloc.h>
#include <atomic>
#include "factory.hpp"
#include "crow_all.h"

#include <boost/thread/mutex.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <sstream>
#include <sys/types.h>
#include <sys/wait.h>

#include "JSON/json/json.h"

#include <fstream> // 添加文件流头文件
using namespace Json;
const std::string data_request_id = "requestId";
boost::interprocess::interprocess_semaphore *sem_in; //  = new boost::interprocess::interprocess_semaphore(0);
boost::interprocess::interprocess_semaphore *sem_proc;
boost::interprocess::interprocess_semaphore *sem_out;
int main(int argc, char **argv)
{
    int port = 8096;
    if (argc >= 3)
    {
        port = std::stoi(argv[2]);
    }
    std::string o;

    crow::SimpleApp app;
    std::mutex mu;

    sem_in = new boost::interprocess::interprocess_semaphore(1);
    sem_proc = new boost::interprocess::interprocess_semaphore(0);
    sem_out = new boost::interprocess::interprocess_semaphore(0);

    Factory f;

    if (!f.initFactory())
    {
        std::cout << "failed to init factory" << std::endl;
        return -1;
    }
    //
    std::string my = "";
    std::string app_host = "";
    std::string app_name = "";
    app.route_dynamic("/").methods("POST"_method)
    ([&o, &mu, &app_name, &app_host, &f, &my](const crow::request &req)
    {
        std::string response = "over";
        std::string requestId;
        std::string image, image1, image2;
        std::string params;
        int index;

        // 其他变量声明

        char *temp = nullptr;
        //CppProcess::Godeye::ErrorCode err_code = CppProcess::Godeye::kNoError;
        //LOG(INFO) << "start, " << req.raw_url;
        std::cout << "start, " << req.raw_url;

        do
        {
            std::string data_request_id;
            requestId = req.url_params.get(data_request_id);
            std::string body = req.body;
            Json::Value root;
            Json::Reader reader;
            //LOG(INFO) << requestId << " start parse" << req.raw_url << " body size " << body.size();

            // 从本地文件获取数据并解析为JSON
            std::ifstream file("path_to_local_file.json"); // 替换为本地文件路径
            if (!file.is_open())
            {
                //LOG(INFO) << "Failed to open the file.";
                std::cout << "Failed to open the file." << std::endl;
                break;
            }

            std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            file.close();

            if (!reader.parse(fileContent.c_str(), fileContent.c_str() + fileContent.size(), root))
            {
                //LOG(INFO) << "File content is not valid JSON.";
                std::cout << "File content is not valid JSON." << std::endl;
                break;
            }
            // 解析结束

            Request m_req(requestId);
            m_req.m_frames.resize(2);
            m_req.m_index = root["index"].asInt();
            Request::strToImage(root["image"].asString(), m_req.m_img);
            //LOG(INFO) << m_req.m_request_id << " get image success.";
            std::cout << m_req.m_request_id << " get image success." << std::endl;
            Request::strToImage(root["image1"].asString(), m_req.m_frames[0]);
            Request::strToImage(root["image2"].asString(), m_req.m_frames[1]);
            //LOG(INFO) << m_req.m_request_id << " parse params ok";
            std::cout<< m_req.m_request_id << " parse params ok"<<std::endl;
            //LOG(INFO) << root["params"].size() << endl;
            std::cout << root["params"].size() << std::endl;
            m_req.m_voca_params.resize(root["params"].size());
            for (int i = 0; i < root["params"].size(); i++) {
                m_req.m_voca_params[i].resize(root["params"][i].size());
                for (int j = 0; j < root["params"][i].size(); j++) {
                    m_req.m_voca_params[i][j] = float(root["params"][i][j].asDouble());
                }
            }

            //LOG(INFO) << m_req.m_request_id << " parse voca params ok. index : " << m_req.m_index;
            std::cout << m_req.m_request_id << " parse voca params ok. index : " << m_req.m_index << std::endl;
            if (m_req.m_img.empty() || m_req.m_frames[0].empty() || m_req.m_frames[1].empty())
            {
                //LOG(INFO) << "parse image error.";
                std::cout << "parse image error." << std::endl;
                break;
            }
            //
            //                cv::imwrite(m_req.m_request_id + "_1.jpeg", m_req.m_img);
            //                cv::imwrite(m_req.m_request_id + "_2.jpeg", m_req.m_frames[0]);
            //                cv::imwrite(m_req.m_request_id + "_3.jpeg", m_req.m_frames[1]);
            int state = int(RunState::FACEBOXESPHASE);
            bool flag = true;
            bool over = false;
            Stage *stage = NULL;
            while (flag && !over) {
                switch (state) {
                case RunState::FACEBOXESPHASE:
                    stage = f.getStage(RunState::FACEBOXESPHASE);
                    flag = stage->parseTask(&m_req);
                    break;
                case RunState::FACELANDMARK:
                    stage = f.getStage(RunState::FACELANDMARK);
                    flag = stage->parseTask(&m_req);
                    break;
                case RunState::FACEMODE:
                    stage = f.getStage(RunState::FACEMODE);
                    flag = stage->parseTask(&m_req);
                    break;
                case RunState::GENPROJBFM:
                    stage = f.getStage(RunState::GENPROJBFM);
                    flag = stage->parseTask(&m_req);
                    break;
                case RunState::GANMOUTH:
                    stage = f.getStage(RunState::GANMOUTH);
                    flag = stage->parseTask(&m_req);
                    break;
                default:
                    over = true;
                    break;
                }
                state = state + 1;
            }

            if (!flag) {
                //LOG(INFO) << requestId << " exec erorr, name : " << stage->getName() << " index : " << m_req.m_index;
                std::cout << requestId << " exec erorr, name : " << stage->getName() << " index : " << m_req.m_index << std::endl;
                break;
            } else {
                //LOG(INFO) << requestId << " exec success. index : " << m_req.m_index;
                std::cout << requestId << " exec success. index : " << m_req.m_index << std::endl;
            }

            if (m_req.m_out.empty()) {
                //LOG(INFO) << requestId << " parse error. index : " << m_req.m_index;
                std::cout << requestId << " parse error. index : " << m_req.m_index<< std::endl;
                break;
            }
            Request::imageToStr(m_req.m_out, response);
            //LOG(INFO) << requestId << " parse over size : " << response.size() << " index : " << m_req.m_index;
            std::cout << requestId << " parse over size : " << response.size() << " index : " << m_req.m_index<< std::endl;

        } while (false);
        return crow::response{response}; 
    });
    app.port(port).multithreaded().run();
    sem_proc->post();
}