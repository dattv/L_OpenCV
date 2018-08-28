#include "include.h"

int main() {
	cv::Mat src1 = cv::imread("D:/2018_research/L_OpenCV/hamy.jpg", cv::IMREAD_ANYCOLOR);
	cv::Mat src2 = cv::imread("D:/2018_research/L_OpenCV/hamy2.jpg", cv::IMREAD_ANYCOLOR);

	if (!src1.empty() && !src2.empty()) {

		//int x = 50;
		//int y = 10;
		//int w = 80;
		//int h = 80;
		//
		//double alpha = 0.5;
		//double beta = 0.5;
		//
		//cv::Mat roi1(src1, cv::Rect(x, y, w, h));
		//cv::Mat roi2(src2, cv::Rect(0, 0, w, h));
		//
		//cv::addWeighted(roi1, alpha, roi2, beta, 0., roi1);

		cv::namedWindow("alpha blend", 1);
		cv::imshow("alpha blend", src1);
		cv::waitKey(0);

	}
	return 0;
}