#pragma once
#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#define M_PI 3.14159265358979323846
#define imgThreshold  550//大图转化的图片大小
#include <opencv2/opencv.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include<opencv2/imgproc/imgproc.hpp>  
#include <stdlib.h>
#include <stdio.h>
#include<string>
#include<sstream> 
#include<math.h>
#include<iostream>
using namespace cv;
using namespace std;
string writePath = "";
string readPath = "D:/桌面/workspace/识别二维码/二维码/DSC_0025.jpg";
double fScale = 1;      //缩放倍数  
int 
Mat src, src_gray, tgray;
vector<vector<Point> > contours;
void findSquares()
{

	/*pyrDown(imgcopy,imgcopy,Size(src.rows,src.cols),7);
	pyrUp(imgcopy,imgcopy, Size(src.rows, src.cols), 7);*/
	//红绿蓝三色分别尝试提取
	Mat timg = Mat(src);
	Mat mv[3];
	split(timg, mv);
	for (int c = 0; c < 3; c++)
	{
		imshow("", mv[c]);
		waitKey();
	}

}
bool init()
{
	src = imread(readPath);
	fScale = 1;
	if (!src.data)
		return 0;
	if (src.rows > 900 || src.cols > 900)
	{
		int minNum = src.rows < src.cols ? src.rows : src.cols;
		double modNum = minNum / imgThreshold;
		fScale = 1 / modNum;
	}
	resize(src, src, Size(src.cols*fScale, src.rows*fScale));//缩放
	cvtColor(src, src_gray, CV_RGB2GRAY);//变成灰度图

	return 1;
}
void on_trackbar()
{
	findSquares();
}
double getCosine(Point2f p1, Point2f p2, Point2f p3)
{
	double x1, x2, y1, y2;
	//获取两个边的向量坐标，坐标中心为p1
	x1 = p2.x - p1.x;
	x2 = p3.x - p1.x;
	y1 = p2.y - p1.y;
	y2 = p3.y - p1.y;
	//计算与余弦
	double cosine = (x1*x2 + y1*y2) / (sqrt(x1*x1 + y1*y1) * sqrt(x2*x2 + y2*y2) + 1e-10);
	return (x1*x2 + y1*y2) / (sqrt(x1*x1 + y1*y1) * sqrt(x2*x2 + y2*y2) + 1e-10);
}



#endif // PS_ALGORITHM_H_INCLUDED