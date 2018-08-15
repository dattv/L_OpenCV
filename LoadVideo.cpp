#include "include.h"

int main() {

	// Set up window name
	cv::namedWindow("example2_10", cv::WINDOW_AUTOSIZE);

	// Declare video
	cv::VideoCapture vCap;

	vCap.open(0);

	if (!vCap.isOpened()) {
		std::cerr << "Could'nt open capture" << std::endl;
		return -1;
	}

	cv::Mat frame;

	while (1) {
		vCap >> frame;
		if (!frame.data) break;
		cv::imshow("example2_10", frame);
		if (cv::waitKey(33) >= 0) break;
	}

	cv::waitKey(0);
	cv::destroyAllWindows();
	return 0;
}