/*
 * face_boxes.hpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#ifndef FACE_BOXES_HPP_
#define FACE_BOXES_HPP_

#include <det_face_boxes.hpp>
#include "stage.hpp"

class FaceBoxesPhase : public Stage {
public:
	FaceBoxesPhase(std::string dir);
	~FaceBoxesPhase();
private:
	bool _initMode();
	bool _parseTask(Request *req);
private:
	facethink::FaceBoxesDetection *m_face_boxes;
	std::string m_lib;
	std::string m_conf;
};

#endif /* FACE_BOXES_HPP_ */
