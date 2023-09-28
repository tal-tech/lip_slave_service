/*
 * face_boxes.cpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#include "face_boxes.hpp"
using namespace std;
using namespace facethink;

FaceBoxesPhase::FaceBoxesPhase(string dir) : Stage()
{
	m_face_boxes = NULL;
	m_name = "face_boxes";//模型名称
	m_lib = dir + "lip/model/det_face_boxes/libpxnn.so";//
	m_conf = dir + "lip/model/config.xml";
}

FaceBoxesPhase::~FaceBoxesPhase()
{
	if (m_face_boxes)
		delete m_face_boxes;
}

bool FaceBoxesPhase::_initMode()
{
	m_face_boxes = FaceBoxesDetection::create(m_lib, m_conf);
	if (m_face_boxes == NULL)
		return false;
	return true;
}

bool FaceBoxesPhase::_parseTask(Request *req)
{
	try
	{
		int ret = m_face_boxes->detection(req->getInputImg(), req->m_rectangles, req->m_confidences);
		if (ret != 0 || req->m_rectangles.empty() || req->m_confidences.empty())
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
	return true;
}
