/*
 * factory.hpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <iostream>
#include <map>
#include "stage.hpp"

enum RunState
{
	FACEBOXESPHASE = 0, // 人脸框架
	FACELANDMARK,		// 人脸标记
	FACEMODE,			// 人脸模式
	GENPROJBFM,			// 模型
	GANMOUTH,			// 嘴型
};

class Factory
{
public:
	Factory();
	~Factory();

public:
	bool initFactory();
	// stage 不需要释放，多线程安全
	Stage *getStage(RunState state);

private:
	std::map<RunState, Stage *> m_stages; // 运行状态&阶段
};

#endif /* FACTORY_HPP_ */
