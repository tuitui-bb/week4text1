#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;


int main()
{
	cv::Mat srcMat = imread("D:\\3.jpg", 0);
	cv::Mat dst;
	threshold(srcMat, dst, 100, 255, THRESH_BINARY_INV);
	cv::Mat d = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));

	morphologyEx(dst, dst, MORPH_OPEN, d);
	
	Mat labels;
	Mat stats;
	Mat centroids;

	int  hxz = connectedComponentsWithStats(dst, labels,
		stats, centroids,
		8, CV_16U);

	std::cout << "回形针的个数= " << hxz-2 << std::endl;
	for (int i = 0; i <hxz; i++)
	{
		cv::Rect rect;
		rect.x = stats.at<int>(i, 0);
		rect.y = stats.at<int>(i, 1);
		rect.width = stats.at<int>(i, 2);
		rect.height = stats.at<int>(i, 3);
		rectangle(srcMat, rect, CV_RGB(255, 0, 0), 4, 8, 0);
	}



	imshow("final", srcMat);
	waitKey(0);
	return 0;

}

