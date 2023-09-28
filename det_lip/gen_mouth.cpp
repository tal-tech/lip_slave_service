/*
 * gen_mouth.cpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#include "gen_mouth.hpp"

using namespace std;
using namespace facethink;

GanMouth::GanMouth(string dir) : Stage() {
	m_mouth = NULL;
	m_name = "gen_mouth_gan";
	m_conf = dir + "lip/model/config.xml";
	m_lib = dir + "lip/model/gen_mouth_gan/libpxnn.so";
}

GanMouth::~GanMouth() {
	if (m_mouth)
		delete m_mouth;
}

bool GanMouth::_initMode() {
	m_mouth = MouthGan::create(m_lib, m_conf);
	if (m_mouth == NULL)
		return false;
	return true;
}

bool GanMouth::_parseTask(Request *req) {
	try {
		int ret = m_mouth->generate(req->m_tmp_out, req->m_frames,
				req->m_landmarks[0], req->m_img);
//		cout << "channel " << req->m_tmp_out.channels();
//		cout << "len " << req->m_frames.size() << " channel " << req->m_frames[0].channels();
//		cout << "mouth ================== " << ret << endl;
		req->m_out = req->m_img.clone();
		if (ret != 0) {
			return false;
		}
	} catch (...){
		return false;
	}

	return true;
}
