#include "include.h"

int main() {

	// Read an image from hardisk
	cv::Mat img_rgb = cv::imread("D:/2018_research/L_OpenCV/hamy.jpg", 1);

	// Create variables for store gray image
	cv::Mat img_gray, img_cny;

	// 
	cv::cvtColor(img_rgb, img_gray, cv::COLOR_BGR2GRAY);


	cv::namedWindow("example origina", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("example canny", cv::WINDOW_AUTOSIZE);

	cv::imshow("example Gray", img_gray);
	
	cv::Canny(img_gray, img_cny, 10, 100, 3, true);
	cv::imshow("example canny", img_cny);

	cv::imshow("example origina", img_rgb);


	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}