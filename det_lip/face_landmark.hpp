/*
 * face_landmark.hpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#ifndef FACE_LANDMARK_HPP_
#define FACE_LANDMARK_HPP_

#include "stage.hpp"
#include <det_landmark_tf.hpp>

class FaceLANDMARKPhase : public Stage {
public:
	FaceLANDMARKPhase(std::string dir);
	~FaceLANDMARKPhase();
private:
	bool _initMode();
	bool _parseTask(Request *req);
private:
	facethink::FaceLandmark *m_face_landmark;
	std::string m_lib;
	std::string m_conf;
};

#endif /* FACE_LANDMARK_HPP_ */
