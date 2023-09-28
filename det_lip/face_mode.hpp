/*
 * face_mode.hpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#ifndef FACE_MODE_HPP_
#define FACE_MODE_HPP_


#include "stage.hpp"
#include <gen_face_mode.hpp>

class FaceModePhase : public Stage {
public:
	FaceModePhase(std::string dir);
	~FaceModePhase();
private:
	bool _initMode();
	bool _parseTask(Request *req);
private:
	facethink::FaceMode *m_face_mode;
	std::string m_lib;
	std::string m_conf;
};


#endif /* FACE_MODE_HPP_ */
