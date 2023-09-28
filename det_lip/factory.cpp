/*
 * factory.cpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#include <iostream>
#include "factory.hpp"
//#include "base/logging.h"
#include "face_boxes.hpp"
#include "face_landmark.hpp"
#include "face_mode.hpp"
#include "gen_proj_bfm.hpp"
#include "gen_mouth.hpp"

using namespace std;
//using namespace logging;

Factory::Factory()
{
	m_stages.clear();
}

Factory::~Factory()
{
	Stage *stage = NULL;

	for (auto mit = m_stages.begin(); mit != m_stages.end(); ++mit)
	{
		stage = mit->second;
		if (stage != NULL)
			delete stage;
	}
	//LOG(INFO) << "destroy factory.";
	m_stages.clear();
}

bool Factory::initFactory()
{
	Stage *stage = NULL;
	string curr_dir = get_current_dir_name(); // 获取当前路径

	curr_dir = curr_dir + "/";
	//简单工厂创建模型
	do
	{
		//人脸框架
		stage = new FaceBoxesPhase(curr_dir);//创建对象
		m_stages[RunState::FACEBOXESPHASE] = stage;//存入map管理
		if (stage == NULL || stage->initMode() == false)
		{
			// LOG(ERROR) << "face boxes phase init error";
			cout << "face boxes phase init error" << endl;
			break;
		}
		// 人脸标记
		stage = new FaceLANDMARKPhase(curr_dir);
		m_stages[RunState::FACELANDMARK] = stage;
		if (stage == NULL || stage->initMode() == false)
		{
			//LOG(ERROR) << "face landmark phase init error";
			cout << "face landmark phase init error" << endl;
			break;
		}
		// 人脸模式
		stage = new FaceModePhase(curr_dir);
		m_stages[RunState::FACEMODE] = stage;

		if (stage == NULL || stage->initMode() == false)
		{
			//LOG(ERROR) << "face mode phase init error";
			cout << "face mode phase init error" << endl;
			break;
		}
		// 模型
		stage = new GenProjBfmPhase(curr_dir);
		m_stages[RunState::GENPROJBFM] = stage;

		if (stage == NULL || stage->initMode() == false)
		{
			//LOG(ERROR) << "face projbfm phase init error";
			cout << "face projbfm phase init error" << endl;
			break;
		}
		// 嘴型
		stage = new GanMouth(curr_dir);
		m_stages[RunState::GANMOUTH] = stage;

		if (stage == NULL || stage->initMode() == false)
		{
			//LOG(ERROR) << "face boxes phase init error";
			cout << "face boxes phase init error" << endl;
			break;
		}

		//LOG(INFO) << "factory init success";
		cout << "factory init success" << endl;
		return true;
	} while (false);

	return false;
}
//获取目前阶段
Stage *Factory::getStage(RunState state)
{
	auto mit = m_stages.find(state);
	if (mit != m_stages.end())
	{
		return mit->second;
	}

	return NULL;
}
