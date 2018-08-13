
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

int playVideo(std::string argv) {

	// Set window name
	cv::namedWindow("Man3D", cv::WINDOW_AUTOSIZE);

	// 
	cv::VideoCapture cap;
	cap.open(argv);

	cv::Mat frame;
	while (1) {
		cap >> frame;
		if (!frame.data) break;
		cv::imshow("Man3D", frame);
		if (cv::waitKey(33) >= 0) break;
	}
	return 1;
}