#ifndef __YOLOV5_H
#define __YOLOV5_H

#include <vector>
#include <iostream>
//#include "nnie_sdk.h"
#include <opencv2/opencv.hpp>

struct BoxInfo
{
	int label;
	float score;
	cv::Rect2f box;
};

class YOLOV5
{
public:
	int init(char* model_path);
	int detect(cv::Mat &image, std::vector<BoxInfo> &bboxs, float threshold=0.5);
	int destroy();
};


#endif
