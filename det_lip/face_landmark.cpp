/*
 * face_landmark.cpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */
#include "face_landmark.hpp"

using namespace std;
using namespace facethink;

FaceLANDMARKPhase::FaceLANDMARKPhase(string dir) : Stage() {
	m_face_landmark = NULL;
	m_name = "det_landmark_tf";
	m_lib = dir + "/lip/model/det_landmark_tf/libpxnn.so";
	m_conf = dir + "lip/model/config.xml";
}

FaceLANDMARKPhase::~FaceLANDMARKPhase() {
	if (m_face_landmark)
		delete m_face_landmark;
}

bool FaceLANDMARKPhase::_initMode() {
	m_face_landmark = FaceLandmark::create(m_lib, m_conf);
	if (m_face_landmark == NULL)
		return false;
	return true;
}

bool FaceLANDMARKPhase::_parseTask(Request *req) {
	try {
		int ret = m_face_landmark->detection(req->getInputImg(), req->m_rectangles, req->m_landmarks, true);
		if (ret != 0 || req->m_landmarks.empty()) {
			return false;
		}
	} catch (...){
		return false;
	}

	return true;
}
