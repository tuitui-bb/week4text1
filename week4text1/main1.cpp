//#include <iostream>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//
//
//int main()
//{
//	cv::Mat srcMat = imread("D:\\1.jpg", 0);
//	cv::Mat result;
//	
//	cv::Mat des=getStructuringElement(0, Size (3,3), Point(-1, -1));
//	int i;
//	Mat labels;
//	Mat stats;
//	Mat centroids;
//	threshold(srcMat, result, 100, 255, THRESH_BINARY);
//	int  yb=connectedComponentsWithStats(result, labels,
//		stats,centroids,
//		8,CV_32S);
//	std::cout << "Ó²±ÒµÄ¸öÊý = "<<yb-1 << std::endl;
//	for (i = 0;i < 11; i++)
//	{
//		cv::Rect rect;
//		rect.x = stats.at<int>(i, 0);
//		rect.y = stats.at<int>(i, 1);
//		rect.width= stats.at<int>(i, 2);
//		rect.height = stats.at<int>(i, 3);
//		rectangle(srcMat, rect, CV_RGB(255, 0, 0), 4, 8, 0);	
//	}
//
//	imshow("final", srcMat);
//	waitKey(0);
//	return 0;
//
//}
//
