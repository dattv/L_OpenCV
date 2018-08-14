#include "include.h"
#include "example.h"

// Global variables 
int g_slider_position = 0;
int g_run = 1, g_dontset = 0; // srart out in single step mode
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *) {
	g_cap.set(CV_CAP_PROP_POS_FRAMES, pos);
	if (!g_dontset)
		g_run = 1;
	g_dontset = 0;
}

int main() {

	// Set name of window and size
	cv::namedWindow("Example2_4", cv::WINDOW_AUTOSIZE);

	// Open video 3D man in some where
	g_cap.open("D:/2018_research/L_OpenCV/Human Flight 3D - Andy carving_(FullHD).avi");

	int frames = (int)g_cap.get(CV_CAP_PROP_FRAME_COUNT);
	int tmpw   = (int)g_cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int tmph   = (int)g_cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	std::cout << "Video has" << frames << "frames of dimensions(" << tmpw << ", " << tmph << ")." << std::endl;

	cv::createTrackbar("Position", "example2_4", &g_slider_position, frames, onTrackbarSlide);

	cv::Mat frame;
	while (1) {
		if (g_run != 0) {
			g_cap >> frame;
			if (!frame.data) break;
			int current_pos = (int)g_cap.get(CV_CAP_PROP_POS_FRAMES);
			g_dontset = 1;
			cv::setTrackbarPos("Position", "example2_4", current_pos);
			cv::imshow("example2_4", frame);
			g_run -= 1;
		}

		char c = (char)cv::waitKey(10);
		if (c == 'c') {
			g_run = 1;
			std::cout << "single step, run = " << g_run << std::endl;
		}
		if (c == 'r') {
			g_run = -1;
			std::cout << "Run mode, rund = " << g_run << std::endl;
		}
		if (c == 27) break;
	}

	cv::destroyWindow("Example2_4");
	return 0;
}