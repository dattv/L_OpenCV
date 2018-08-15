#include "include.h"

int main() {
	int x = 16;
	int y = 32;

	cv::Mat img_rgb, img_gry, img_pyr, img_cny;

	img_rgb = cv::imread("D:/2018_research/L_OpenCV/hamy.jpg", 1);

	cv::Vec3b intensity = img_rgb.at < cv::Vec3b >(y, x);

	uchar blue = intensity.val[0];
	uchar green = intensity.val[1];
	uchar red = intensity.val[2];

	//std::cout << "At (x, y) = (" << x << ", " << y << "): (blue, green red) = (" << (unsigned int)blue << ", " << (unsigned int)green << ", " << (unsigned int)red << ")" << std::endl;
	//std::cout << "Gray pixel there is: " << (unsigned int)img_gry.at<uchar>(x, y) << std::endl;
	
	x /= 4; y /= 4;
	
	cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
	cv::pyrDown(img_gry, img_pyr);
	cv::Canny(img_rgb, img_cny, 10, 100, 3, true);
	for (int i = 10; i < 50; i++) {
		for (int j = 10; j < 50; j++) {
			img_cny.at<uchar>(i, j) = 128;
		}
	}
	

	cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("gry", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("pyr", cv::WINDOW_AUTOSIZE);

	cv::imshow("original", img_rgb);
	cv::imshow("gry", img_gry);
	cv::imshow("pyr", img_cny);
	
	cv::waitKey(0);
	cv::destroyAllWindows();
}