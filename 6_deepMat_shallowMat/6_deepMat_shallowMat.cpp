// 6_deepMat_shallowMat.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//读取本地的一张图片，对比深复制和浅复制的区别，并显示出来
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/推文/1.jpg");
	cv::Mat deepMat, shallowMat; //分别命名采用深浅复制的图像
	srcMat.copyTo(deepMat); //深复制
	shallowMat = srcMat; //浅复制

	int height = srcMat.rows; //行数
	int width = srcMat.cols; //每行元素的总元素数量
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			//-----------------开始处理每个像素-----------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] +
				srcMat.at<Vec3b>(j, i)[2]) / 3;
			uchar threshold = 80;
			average > threshold ? average = 255 : average = 0;
			srcMat.at<Vec3b>(j, i)[0] = srcMat.at<Vec3b>(j, i)[1] = srcMat.at<Vec3b>(j, i)[2] = average;

			//-------------结束像素处理------------------------
		} //单行处理结束
	}
	imshow("src", srcMat); //展示三张图片对比
	imshow("deep", deepMat);
	imshow("shallow", shallowMat);
	//等待用户按键
	waitKey(0);
	return 0;
}

