/*
 * face_mode.cpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#include "face_mode.hpp"

using namespace std;
using namespace facethink;

FaceModePhase::FaceModePhase(string dir) : Stage() {
	m_face_mode = NULL;
	m_conf = dir + "lip/model/config.xml";
	m_lib = dir + "lip/model/gen_face_mode/libpxnn.so";
	m_name = "gen_face_mode";
}

FaceModePhase::~FaceModePhase() {
	if (m_face_mode)
		delete m_face_mode;
}

bool FaceModePhase::_initMode() {
	m_face_mode = FaceMode::create(m_lib, m_conf);
	if (m_face_mode == NULL)
		return false;
	return true;
}

bool FaceModePhase::_parseTask(Request *req) {
	try {
		int status = m_face_mode->generate(req->getInputImg(), req->m_landmarks[0], req->m_args3d, true);
        if (status != 0 || req->m_args3d.size() != 7) {
            return false;
        }

        req->m_args3d[1] = req->m_voca_params[req->m_index - 2];
	} catch (...) {
		return false;
	}

	return true;
}
