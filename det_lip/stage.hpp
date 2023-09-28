/*
 * stage.hpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#ifndef STAGE_HPP_
#define STAGE_HPP_

#include <iostream>
#include <string>
#include <mutex>
#include "request.hpp"

class Stage {
public:
	Stage();
	virtual ~Stage();
public:
	bool initMode();
	bool parseTask(Request *req);
	std::string &getName();
protected:
	//派生类必须实现
	virtual bool _parseTask(Request *req) = 0;
	virtual bool _initMode() = 0;
private:
	std::mutex m_mutex;
	std::string m_dir;
protected:
	std::string m_name;
};

#endif /* STAGE_HPP_ */
