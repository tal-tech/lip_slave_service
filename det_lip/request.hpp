/*
 * request.hpp
 *
 *  Created on: 2020年5月9日
 *      Author: ym
 */

#ifndef REQUEST_HPP_
#define REQUEST_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/vector.hpp>

class Request {
public:
	Request(std::string id);
public:
	static bool imageToStr(const cv::Mat &mat, std::string &str);
	static bool strToImage(const std::string &str, cv::Mat &mat);
	static bool decodeBase64(const std::string &base64, std::string &result);
	static bool encodeBase64(const std::string &result, std::string &base64);
	static bool decodeBase64(const std::string &base64, std::vector<uchar> &result);
	static bool encodeBase64(const std::vector<uchar> &result, std::string &base64);
	static void getRandStr(std::string &resp);
public:
	const cv::Mat &getInputImg();
	cv::Mat &getOutputImg();
public://init params
	std::string m_origin_video_path;
	std::string m_merge_video_path;
	std::string m_target_video_path;
	std::string m_audio_path;
	std::string m_merge_audio_path;
	std::string m_origin_audio_path;
	std::string m_request_id;
	std::string m_tts_text;
	std::string m_tts_response;
	std::vector<cv::Mat> *m_imgs;
	bool m_use_voca;
	int m_frame_num;
	int m_frame_fps;
	int m_frame_width;
	int m_frame_height;
public://pipe params
	int m_index;
	//输入
	cv::Mat m_img;
	//输出
	cv::Mat m_out;
	cv::Mat m_tmp_out;
	//接受主服务前两帧的数据
	std::vector<cv::Mat> m_frames;
	std::vector<cv::Rect> m_rectangles;
	std::vector<float> m_confidences;
	std::vector<std::vector<cv::Point2f>> m_landmarks;
	std::vector<std::vector<float>> m_voca_params;
	std::vector<std::vector<float>> m_args3d;
	std::vector<cv::Mat> m_speech_features;
	std::vector<cv::Mat> m_images;
	std::vector<cv::Mat> m_out_images;
	std::vector<std::string> m_str_images;
public:
	//有两针数据需要单独的pipeline
	std::vector<std::vector<float>> m_start_args3d;
	std::vector<std::vector<float>> m_end_args3d;
};

#endif /* REQUEST_HPP_ */
