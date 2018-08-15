#include "include.h"

int main() {

	cv::Mat img_rgb = cv::imread("D:/2018_research/L_OpenCV/hamy.jpg", 1);
	cv::Mat img_gray, img_cny, img_pyr;

	cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);
	cv::pyrDown(img_gray, img_pyr);
	cv::Canny(img_pyr, img_cny, 10, 100, 3, true);

	cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("pyr_gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("canny", cv::WINDOW_AUTOSIZE);

	cv::imshow("Original", img_rgb);
	cv::imshow("pyr_gray", img_pyr);
	cv::imshow("canny", img_cny);

	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}