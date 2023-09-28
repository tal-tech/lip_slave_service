/*
 * gen_proj_bfm.cpp
 *
 *  Created on: 2020年5月11日
 *      Author: ym
 */

#include <vector>
#include "gen_proj_bfm.hpp"

using namespace std;
using namespace facethink;

GenProjBfmPhase::GenProjBfmPhase(string dir) : Stage() {
	m_proj_bfm = NULL;
	m_name = "gen_proj_bfm";
	m_conf = dir + "lip/model/config.xml";
	m_lib = dir + "lip/model/gen_proj_bfm/libpxnn.so";
}

GenProjBfmPhase::~GenProjBfmPhase() {
	if (m_proj_bfm)
		delete m_proj_bfm;
}

bool GenProjBfmPhase::_initMode() {
	m_proj_bfm = GenProjBfm::create(m_lib, m_conf);
	if (m_proj_bfm == NULL)
		return false;
	return true;
}

bool GenProjBfmPhase::_parseTask(Request *req) {
    vector<float> arg_params;
    vector<float> transform_params = req->m_args3d.back();

    for (size_t i = 0; i < req->m_args3d.size() - 1; i++) {
        arg_params.insert(arg_params.end(), req->m_args3d[i].begin(), req->m_args3d[i].end());
    }

	try {
		int ret = m_proj_bfm->generate(arg_params, transform_params, req->m_tmp_out);

		if (ret != 0 || req->m_tmp_out.empty()) {
			return false;
		}
	} catch (...){
		return false;
	}

	return true;
}

