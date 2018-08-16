#include "include.h"

int main() {
	CvCapture *capture = 0;
	IplImage *log_polar_img = 0;
	IplImage *lin_polar_img = 0;
	IplImage *recovered_img = 0;

	char *name = "D:/2018_research/L_OpenCV/Human Flight 3D - Andy carving_(FullHD).avi";
	capture = cvCaptureFromAVI(name);

	cv::namedWindow("linear_polar", 0);
	cv::namedWindow("log_polar", 0);
	cv::namedWindow("recovered_image", 0);

	cvMoveWindow("linear_polar", 20, 20);
	cvMoveWindow("log_polar", 700, 20);
	cvMoveWindow("recovered_image", 20, 700);

	for (;;) {
		IplImage *frame = 0;
		if (!frame) break;

		if (!log_polar_img) {
			log_polar_img = cvCreateImage(cvSize(frame->width, frame->height), IPL_DEPTH_8U, frame->nChannels);
			lin_polar_img = cvCreateImage(cvSize(frame->width, frame->height), IPL_DEPTH_8U, frame->nChannels);
			recovered_img = cvCreateImage(cvSize(frame->width, frame->height), IPL_DEPTH_8U, frame->nChannels);
		}

		//cvLogPolar(frame, log_polar_img, cv::Point2f(frame->width/2, frame->height/2), (double)70, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
		//cvLinearPolar(frame, lin_polar_img, cvPoint2D32f(frame->width >> 1, frame->height >> 1), 70, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
		//
		//cvLogPolar(log_polar_img, recovered_img, cv::Point2f(frame->width / 2, frame->height / 2), (double)70, CV_WARP_INVERSE_MAP + CV_INTER_LINEAR);

		//cvShowImage("log_polar", log_polar_img);
		//cvShowImage("linear_polar", lin_polar_img);
		//cvShowImage("recovered_image", recovered_img);
		cvShowImage("original", frame);

		if (cv::waitKey(10) >= 0) break;
	}

	cvReleaseCapture(&capture);
	cv::destroyWindow("linear_polar");
	cv::destroyWindow("log_polar");
	cv::destroyWindow("recovered_image");

	return 0;
}