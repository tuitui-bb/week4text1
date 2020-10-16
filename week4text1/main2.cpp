#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;


int main()
{
	cv::Mat srcMat = imread("D:\\2.jpg", 0);
	cv::Mat dst;
	threshold(srcMat, dst, 100, 255, THRESH_BINARY_INV);
	cv::Mat d = getStructuringElement(MORPH_ELLIPSE, Size(20, 20));
	cv::Mat d2 = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));

	morphologyEx(dst, dst, MORPH_OPEN, d);
	morphologyEx(dst, dst, MORPH_CLOSE, d2);
	Mat labels;
	Mat stats;
	Mat centroids;

	int  yd = connectedComponentsWithStats(dst, labels,
		stats, centroids,
		8, CV_32S);

	std::cout << "圆点的个数 = " << yd - 1 << std::endl;
	


	imshow("final", dst);
	waitKey(0);
	return 0;

}

