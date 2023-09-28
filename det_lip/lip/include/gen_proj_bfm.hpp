///////////////////////////////////////////////////////////////////////////////////////
#ifndef __FACETHINK_API_GEN_PROJ_BFM_HPP__
#define __FACETHINK_API_GEN_PROJ_BFM_HPP__

#include <string>
#include <math.h>
#include <opencv2/opencv.hpp>

#ifdef WIN32
#ifdef DLL_EXPORTS
#define EXPORT_CLASS   __declspec(dllexport)
#define EXPORT_API  extern "C" __declspec(dllexport)
#define EXPORT_CLASS_API
#else
#define EXPORT_CLASS   __declspec(dllimport )
#define EXPORT_API  extern "C" __declspec(dllimport )
#endif
#else
#define EXPORT_CLASS
#define EXPORT_API  extern "C" __attribute__((visibility("default")))
#define EXPORT_CLASS_API __attribute__((visibility("default")))
#endif
namespace facethink {
    class EXPORT_CLASS GenProjBfm {
    public:
        EXPORT_CLASS_API explicit GenProjBfm(void);

        EXPORT_CLASS_API virtual ~GenProjBfm(void);

		/**
		 * @brief SDK初始化函数，必须先于其他SDK函数之前调用
		 * @param [in] pxnn_library_file SDK对应的pxnn动态库文件路径
		 * @param [in] config_file SDK对应的xml配置文件路径，详情见config.xml文件
		 * @remarks 初始化函数需要读取模型等文件，需要等待一定时间
		*/
        EXPORT_CLASS_API static GenProjBfm *create(
                const std::string &pxnn_library_file,
                const std::string &config_file);

        /**
         * \brief 对每一帧生成映射图(debug版本,输出landmark2d)
         * @param [in] arg_params size为257的参数列表
         * @param [in] transform_params size为5的转换参数
         * @param [out] proj_img 生成的投影图片(BGR格式)
         * @param [out] landmark_2d 映射后的landmark2D
         * @return
		 * @retval -1 SDK初始化失败
		 * @retval -2 SDK离线鉴权失败
		 * @retval -3 前向推理失败
         * @retval -4：参数尺寸错误
         * @retval -5 生成映射图片失败
         */
        EXPORT_CLASS_API virtual int
        generate_debug(const std::vector<float> &arg_params, const std::vector<float> &transform_params,
                       cv::Mat &proj_img, std::vector<cv::Point2f> &landmark_2d) = 0;

        /**
         * \brief 对每一帧生成映射图(debug版本,输出landmark2d)
         * @param [in] arg_params size为257的参数列表
         * @param [in] transform_params size为5的转换参数
         * @param [out] proj_img 生成的投影图片(BGR格式)
         * @param [out] landmark_2d 映射后的landmark2D
         * @return
		 * @retval -1 SDK初始化失败
		 * @retval -2 SDK离线鉴权失败
		 * @retval -3 前向推理失败
         * @retval -4：参数尺寸错误
         * @retval -5 生成映射图片失败
         */
        EXPORT_CLASS_API virtual int
        generate(const std::vector<float> &arg_params, const std::vector<float> &transform_params,
                 cv::Mat &proj_img) = 0;
    };
}
#endif //__FACETHINK_API_GEN_PROJ_BFM_HPP__