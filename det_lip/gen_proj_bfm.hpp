/*
 * gen_proj_bfm.hpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#ifndef GEN_PROJ_BFM_HPP_
#define GEN_PROJ_BFM_HPP_

#include "stage.hpp"
#include <gen_proj_bfm.hpp>

class GenProjBfmPhase : public Stage {
public:
	GenProjBfmPhase(std::string dir);
	~GenProjBfmPhase();
private:
	bool _initMode();
	bool _parseTask(Request *req);
private:
	facethink::GenProjBfm *m_proj_bfm;
	std::string m_lib;
	std::string m_conf;
};

#endif /* GEN_PROJ_BFM_HPP_ */
