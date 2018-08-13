
#include "example.h"

int example01() {

	cv::Mat img = cv::imread("D:/2018_research/L_OpenCV/hamy.jpg", 1);
	if (img.empty()) return -1;
	cv::namedWindow("Hamy", cv::WINDOW_AUTOSIZE);
	cv::imshow("Hamy", img);
	cv::waitKey(0);
	cv::destroyWindow("Hamy");
	return 1;
}