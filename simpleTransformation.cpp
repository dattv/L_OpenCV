
#include "include.h"

int main() {

	cv::Mat img = cv::imread("D:/2018_research/L_OpenCV/hamy.jpg", 1);

	// Create some windows to show the input and output imgae in.
	cv::namedWindow("Example2_5-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example2_5-out", cv::WINDOW_AUTOSIZE);

	// Create a window to show out input image
	cv::imshow("Example2_5-in", img);

	// Create an imgae to hold the smoothed ouput
	cv::Mat out;

	// Do smoothing
	cv::GaussianBlur(img, out, cv::Size(5, 5), 3, 3);

	cv::imshow("Example2_5-out", out);

	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}