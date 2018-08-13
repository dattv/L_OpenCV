
#include "example.h"

int example01() {
	// Read image
	cv::Mat img = cv::imread("D:/2018_research/L_OpenCV/hamy.jpg", 1);
	// Check reading image
	if (img.empty()) return -1;
	// Set window size to naturally size of image
	cv::namedWindow("Hamy", cv::WINDOW_AUTOSIZE);
	// Print image to screen
	cv::imshow("Hamy", img);
	// wait for a keystroke 
	cv::waitKey(0);
	// deallocation of images
	cv::destroyWindow("Hamy");
	return 1;
}