#include<tools.h>
#include<iostream>
using namespace cv;
using namespace std;
double getCosine(Point2f p1, Point2f p2, Point2f p3);
void on_trackbar();
bool init();
void findSquares();//²éÕÒËÄ±ßĞÎ
int main()
{
	if (!init())
		return -1;
	on_trackbar();
	waitKey();





}
