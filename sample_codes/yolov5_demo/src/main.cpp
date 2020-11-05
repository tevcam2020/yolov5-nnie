#include <iostream>
#include <opencv2/opencv.hpp>

#include "yolov5.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <test image path>!\n";
		return -1;
	}
	
	YOLOV5 yolov5;
	std::string model_path = "../models/yolov5-voc.wk";
	int ret = yolov5.init((char*)model_path.c_str());

	cv::Mat image = cv::imread(argv[1]);
	if(image.empty())
	{
		std::cout << "input image is empty!!!\n";
		return -1;
	}
	
	std::vector<BoxInfo> bboxs;
	ret = yolov5.detect(image, bboxs);
	for(int i = 0; i < bboxs.size(); i++){
		cv::rectangle(image, bboxs[i].box, cv::Scalar(0, 255, 0), 2, 8, 0);
	}
	cv::imwrite("result.jpg", image);
	yolov5.destroy();
	return 0;
}
