/*
 * stage.cpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#include <iostream>
#include "base/logging.h"
#include "stage.hpp"

using namespace std;
using namespace std;

Stage::Stage() {
}

Stage::~Stage() {
}

bool Stage::initMode() {
	try {
		//LOG(INFO) << " init " << m_name << " mode .";
		bool flag = _initMode();
		if (flag) {
			//LOG(INFO) << " init " << m_name << "succ.";
		} else {
			//LOG(INFO) << " init " << m_name << " error.";
		}
		return flag;
	} catch(...) {
		return false;
	}
}

bool Stage::parseTask(Request *req) {
	bool flag = true;
	do {
		lock_guard<mutex> guard(m_mutex);
		//LOG(INFO) << "requestId " << req->m_request_id << " " << this->getName() << " start parse.";
		flag = this->_parseTask(req);
		//LOG(INFO) << "requestId " << req->m_request_id << " " << this->getName() << " parse over.";
	} while(false);
	return flag;
}

string &Stage::getName() {
	return m_name;
}
