#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;


int main()
{
	cv::Mat srcMat = imread("D:\\2.jpg", 0);
	//cv::Mat dst = 255 - srcMat;
	cv::Mat dst;
	cv::bitwise_not(srcMat, dst);
	threshold(dst, dst, 100, 255, THRESH_OTSU);
	cv::Mat d = getStructuringElement(0, Size(20, 20));
	cv::Mat d2 = getStructuringElement(0, Size(5, 5));

	morphologyEx(dst, dst, MORPH_OPEN, d);
	morphologyEx(dst, dst, MORPH_CLOSE, d2);
	Mat labels;
	Mat stats;
	Mat centroids;

	int  yd = connectedComponentsWithStats(dst, labels,
		stats, centroids,
		8, CV_32S);

	std::cout << "圆点的个数 = " << yd - 1 << std::endl;
	for (int i = 0; i < yd; i++)
	{
		cv::Rect rect;
		rect.x = stats.at<int>(i, 0);
		rect.y = stats.at<int>(i, 1);
		rect.width = stats.at<int>(i, 2);
		rect.height = stats.at<int>(i, 3);
		rectangle(srcMat, rect, CV_RGB(255, 0, 0), 4, 8, 0);
	}



	imshow("final", dst);
	imshow("final2", srcMat);
	waitKey(0);
	return 0;

}

