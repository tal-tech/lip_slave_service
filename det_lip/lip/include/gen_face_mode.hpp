///////////////////////////////////////////////////////////////////////////////////////
///  Copyright (C) 2017, TAL AILab Corporation, all rights reserved.
///
///  @file: gen_face_mode.hpp
///  @brief 三维参数预测
///  @details 最初版本
//
//
///  @version 1.0.0.0
///  @author Qiao Yu
///  @date 2019-12-17
///
///  @see 使用参考：demo.cpp
///
///////////////////////////////////////////////////////////////////////////////////////
#ifndef __FACETHINK_API_GEN_FACE_MODE_HPP__
#define __FACETHINK_API_GEN_FACE_MODE_HPP__
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
class EXPORT_CLASS FaceMode
{
public:
	EXPORT_CLASS_API explicit FaceMode(void);
	EXPORT_CLASS_API virtual ~FaceMode(void);
	/**
		 * @brief SDK初始化函数，必须先于其他SDK函数之前调用
		 * @param [in] pxnn_library_file SDK对应的pxnn动态库文件路径
		 * @param [in] config_file SDK对应的xml配置文件路径，详情见config.xml文件
		 * @remarks 初始化函数需要读取模型等文件，需要等待一定时间
		*/
	EXPORT_CLASS_API static FaceMode *create(
		const std::string &det_model_file,
		const std::string &config_file);

	/**
		* @brief 人脸框检测
		 * @param [in] img 输入的图像数据，仅支持如下一种格式：
		 * - 1.BGR图：img为一维数组，每个元素（字节）表示一个像素点的单通道取值，三个连续元素表示一个像素点的三通道取值，顺序为BGR。
		 * @param [in] lmks 人脸关键点检测det_landmark_tf输出的106个关键点
		 * @param [out] args3d 人脸3D参数的输出
		 * @return 
		 * @retval 0 检测成功
		 * @retval -1 SDK初始化失败
		 * @retval -2 SDK离线鉴权失败
		 * @retval -3 前向推理失败
		 * @retval -4 图片为空或者图片通道不为3
		*/
	EXPORT_CLASS_API virtual int generate(const cv::Mat &img, const std::vector<cv::Point_<float>> &lmks, std::vector<std::vector<float>> &args3d, bool is_rgb_format = false) = 0;
};
} // namespace facethink
#endif
