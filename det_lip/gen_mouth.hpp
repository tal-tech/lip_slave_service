/*
 * gen_mouth.hpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#ifndef GEN_MOUTH_HPP_
#define GEN_MOUTH_HPP_


#include "stage.hpp"
#include <gen_mouth_gan.hpp>

class GanMouth : public Stage {
public:
	GanMouth(std::string dir);
	~GanMouth();
private:
	bool _initMode();
	bool _parseTask(Request *req);
private:
	facethink::MouthGan *m_mouth;
	std::string m_lib;
	std::string m_conf;
};


#endif /* GEN_MOUTH_HPP_ */
