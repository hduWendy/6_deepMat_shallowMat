// 6_deepMat_shallowMat.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//��ȡ���ص�һ��ͼƬ���Ա���ƺ�ǳ���Ƶ����𣬲���ʾ����
	cv::Mat srcMat = imread("C:/Users/lenovo/Desktop/����/1.jpg");
	cv::Mat deepMat, shallowMat; //�ֱ�����������ǳ���Ƶ�ͼ��
	srcMat.copyTo(deepMat); //���
	shallowMat = srcMat; //ǳ����

	int height = srcMat.rows; //����
	int width = srcMat.cols; //ÿ��Ԫ�ص���Ԫ������
	for (int j = 0; j<height; j++)
	{
		for (int i = 0; i<width; i++)
		{
			//-----------------��ʼ����ÿ������-----------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] +
				srcMat.at<Vec3b>(j, i)[2]) / 3;
			uchar threshold = 80;
			average > threshold ? average = 255 : average = 0;
			srcMat.at<Vec3b>(j, i)[0] = srcMat.at<Vec3b>(j, i)[1] = srcMat.at<Vec3b>(j, i)[2] = average;

			//-------------�������ش���------------------------
		} //���д������
	}
	imshow("src", srcMat); //չʾ����ͼƬ�Ա�
	imshow("deep", deepMat);
	imshow("shallow", shallowMat);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}

