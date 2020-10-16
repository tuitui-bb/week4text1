//#include <iostream>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//
//
//int main()
//{
//	cv::Mat srcMat = imread("D:\\1.jpg", 0);
//	
//	cv::Mat dst;
//	threshold(srcMat, dst, 100, 255, THRESH_BINARY);
//	cv::Mat kernel =  getStructuringElement(0, Size(3,3), Point(-1, -1));
//	erode(dst, dst, kernel,
//		Point(-1, -1),1);
//	dilate(dst,dst,  kernel,
//		Point(-1, -1), 1);
//	
//
//	imshow("final", dst);
//	waitKey(0);
//	return 0;
//	
//	}
//
