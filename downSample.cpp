#include "include.h"

int main() {

	// read image
	cv::Mat img = cv::imread("D:/2018_research/L_OpenCV/hamy.jpg", 1);
	cv::Mat img2;

	// Set name for window
	cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);

	// screen original image
	cv::imshow("Example1", img);

	// downSample original imgae
	cv::pyrDown(img, img2);

	// screen the downscale image
	cv::imshow("Example2", img2);

	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}