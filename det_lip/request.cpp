/*
 * request.cpp
 *
 *  Created on: 2020年5月9日
 *      Author: ym
 */

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgcodecs/legacy/constants_c.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>

#include "base/logging.h"
#include "request.hpp"
#include "base/base64.h"

using namespace std;
using namespace cv;
using namespace logging;
using namespace boost;

Request::Request(string id) {
	m_request_id = id;
	m_use_voca = false;
	m_imgs = NULL;
	m_index = 0;
	m_frame_num = 0;
	m_frame_fps = 0;
	m_frame_width = 0;
	m_frame_height = 0;
}

bool Request::imageToStr(const Mat &mat, string &str) {
//	ostringstream os;
//	string result;
//	archive::binary_oarchive bo(os);
//	bo << mat;
//	result = os.str();
//
//	Request::encodeBase64(result, str);
	vector<int> param = std::vector<int>(2);
	vector<uchar> buff;
	string result;
	param[0] = CV_IMWRITE_JPEG_QUALITY;
	param[1] = 80; // default(95) 0-100
	imencode(".jpg", mat, buff, param);
//	result.resize(buff.size());
//	memcpy((char *)result.data(), &buff[0], buff.size());
	result.reserve(buff.size());
	for (auto &item : buff) {
		result += item;
	}
	base::Base64Encode(result, &str);

	return true;
}

bool Request::strToImage(const std::string &str, cv::Mat &mat) {
//	string result;
//	Request::decodeBase64(str, result);
//	istringstream is(result);
//	archive::binary_iarchive ia(is);
//	ia >> mat;
//	str.resize(mat.rows*mat.cols*mat.elemSize());
//	for (int i = 0; i < str.size(); i++) {
//		mat.data[i] = str;
//	}
	vector<uchar> buff;
	string result;
	base::Base64Decode(str, &result);
	buff.resize(result.size());
	memcpy(&buff[0], result.c_str(), result.size());
	imdecode(buff, CV_LOAD_IMAGE_COLOR, &mat);
	return true;
}

const Mat &Request::getInputImg() {
	return m_img;
}

void Request::getRandStr(string &resp) {
	uuids::uuid a_uuid = uuids::random_generator()();
	resp = uuids::to_string(a_uuid);
}

Mat &Request::getOutputImg() {
	return m_out;
}

bool Request::decodeBase64(const string &base64, vector<uchar> &bresult) {
	typedef boost::archive::iterators::transform_width<boost::archive::iterators::binary_from_base64<string::const_iterator>, 8, 6> Base64DecodeIterator;
	stringstream result;
	try {
		copy(Base64DecodeIterator(base64.begin()) , Base64DecodeIterator(base64.end()), ostream_iterator<char>(result));
	} catch(...) {
		return false;
	}
//	bresult = result.str();
	string str = result.str();
	bresult.resize(str.size());
	memcpy(&bresult[0], str.data(), str.size());
//	for (int i = 0; i < str.size(); ++i) {
//		bresult[i] = str[i];
//	}
	return bresult.empty() == false;
}

bool Request::encodeBase64(const vector<uchar> &bresult, string &base64) {
//	typedef boost::archive::iterators::base64_from_binary<boost::archive::iterators::transform_width<string::const_iterator, 6, 8> > Base64EncodeIterator;
//	stringstream result;
//	copy(Base64EncodeIterator(bresult.begin()) , Base64EncodeIterator(bresult.end()), ostream_iterator<char>(result));
//	size_t equal_count = (3 - bresult.size() % 3) % 3;
//	for (size_t i = 0; i < equal_count; i++) {
//		result.put('=');
//	}
//	base64 = result.str();
	return base64.empty() == false;
}

bool Request::decodeBase64(const string &base64, string &bresult) {
//	typedef boost::archive::iterators::transform_width<boost::archive::iterators::binary_from_base64<string::const_iterator>, 8, 6> Base64DecodeIterator;
//	stringstream result;
//	try {
//		copy(Base64DecodeIterator(base64.begin()) , Base64DecodeIterator(base64.end()), ostream_iterator<char>(result));
//	} catch(...) {
//		return false;
//	}
//	bresult = result.str();
	base::Base64Decode(base64, &bresult);
	return bresult.empty() == false;
}

bool Request::encodeBase64(const string &bresult, string &base64) {
//	typedef boost::archive::iterators::base64_from_binary<boost::archive::iterators::transform_width<string::const_iterator, 6, 8> > Base64EncodeIterator;
//	stringstream result;
//	copy(Base64EncodeIterator(bresult.begin()) , Base64EncodeIterator(bresult.end()), ostream_iterator<char>(result));
//	size_t equal_count = (3 - bresult.length() % 3) % 3;
//	for (size_t i = 0; i < equal_count; i++) {
//		result.put('=');
//	}
//	base64 = result.str();
	base::Base64Encode(bresult, &base64);
	return base64.empty() == false;
}

BOOST_SERIALIZATION_SPLIT_FREE(cv::Mat)
namespace boost {
namespace serialization {

    /*** Mat ***/
    template<class Archive>
    void save(Archive & ar, const cv::Mat& m, const unsigned int version) {
      size_t elemSize = m.elemSize(), elemType = m.type();

      ar & m.cols;
      ar & m.rows;
      ar & elemSize;
      ar & elemType; // element type.
      size_t dataSize = m.cols * m.rows * m.elemSize();

      //cout << "Writing matrix data rows, cols, elemSize, type, datasize: (" << m.rows << "," << m.cols << "," << m.elemSize() << "," << m.type() << "," << dataSize << ")" << endl;

      for (size_t dc = 0; dc < dataSize; ++dc) {
          ar & m.data[dc];
      }
    }

    template<class Archive>
    void load(Archive & ar, cv::Mat& m, const unsigned int version)
    {
        int cols, rows;
        size_t elemSize, elemType;

        ar & cols;
        ar & rows;
        ar & elemSize;
        ar & elemType;

        m.create(rows, cols, elemType);
        size_t dataSize = m.cols * m.rows * elemSize;

        //cout << "reading matrix data rows, cols, elemSize, type, datasize: (" << m.rows << "," << m.cols << "," << m.elemSize() << "," << m.type() << "," << dataSize << ")" << endl;

        for (size_t dc = 0; dc < dataSize; ++dc) {
                  ar & m.data[dc];
        }
    }
}
}
