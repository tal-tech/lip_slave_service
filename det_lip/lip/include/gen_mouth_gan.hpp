///////////////////////////////////////////////////////////////////////////////////////
#ifndef __FACETHINK_API_GEN_MOUTH_GAN_HPP__
#define __FACETHINK_API_GEN_MOUTH_GAN_HPP__

#include <string>
#include <math.h>
#include <opencv2/opencv.hpp>

#ifdef WIN32
#ifdef DLL_EXPORTS
#define EXPORT_CLASS __declspec(dllexport)
#define EXPORT_API extern "C" __declspec(dllexport)
#define EXPORT_CLASS_API
#else
#define EXPORT_CLASS __declspec(dllimport)
#define EXPORT_API extern "C" __declspec(dllimport)
#endif
#else
#define EXPORT_CLASS
#define EXPORT_API extern "C" __attribute__((visibility("default")))
#define EXPORT_CLASS_API __attribute__((visibility("default")))
#endif
namespace facethink
{
class EXPORT_CLASS MouthGan
{
public:
    EXPORT_CLASS_API explicit MouthGan(void);

    EXPORT_CLASS_API virtual ~MouthGan(void);

    /**
		 * @brief SDK初始化函数，必须先于其他SDK函数之前调用
		 * @param [in] pxnn_library_file SDK对应的pxnn动态库文件路径
		 * @param [in] config_file SDK对应的xml配置文件路径，详情见config.xml文件
		 * @remarks 初始化函数需要读取模型等文件，需要等待一定时间
		*/
    EXPORT_CLASS_API static MouthGan *create(
        const std::string &model_file,
        const std::string &config_file);

    /**
         * \brief 对每一帧进行唇形合成
         * @param [in] projection_img 投影图片
         * @param [in] fore_frames 前两帧视频帧
         * @param [in] landmarks 人脸landmark(106个)
         * @param [out] frame 当前帧,合成结果直接修改到该帧
         * @param [in] is_rgb_format 是否为RGB格式, 当为默认值false时,表示输入图片为BGR格式
         * @return
         * @retval 0 检测成功
		 * @retval -1 SDK初始化失败
		 * @retval -2 SDK离线鉴权失败
		 * @retval -3 前向推理失败
		 * @retval -4 图片为空或者图片通道不为3
         * 
         */
    EXPORT_CLASS_API virtual int
    generate(const cv::Mat &projection_img, const std::vector<cv::Mat> &fore_frames, const std::vector<cv::Point2f> &landmarks, cv::Mat &frame, bool is_rgb_format = false) = 0;
};
} // namespace facethink
#endif //__FACETHINK_API_GEN_MOUTH_GAN_HPP__