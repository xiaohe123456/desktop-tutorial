#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	int width = 439;		//变换后图像大小
	int height = 570;
	ofstream points;
	points.open("points.txt", ios::out);
	Point3d point;

	//point.x = 0.0458149;
	//point.z = 0.611243;
	//point.y = 1.84523;
	point.x = -0.969545;
	point.z = 3.24914;
	point.y = 0.447072;
	points << fixed << setprecision(6) << point.x << " " << point.y << " " << point.z << endl;

	//point.x = -0.311146;
	//point.z = 0.542593;
	//point.y = 1.53438;
	point.x = -0.679361;
	point.z = 2.34664;
	point.y = 0.570891;
	points << fixed << setprecision(6) << point.x << " " << point.y << " " << point.z << endl;

	//point.x = -0.341513;
	//point.z = 0.371109;
	//point.y = 1.76527;
	point.x = -0.627407;
	point.z = 2.41783;
	point.y = 0.124808;
	points << fixed << setprecision(6) << point.x << " " << point.y << " " << point.z << endl;

	//point.x = 0.145784;
	//point.z = 0.398173;
	//point.y = 1.67491;
	point.x = -0.979542;
	point.z = 3.25341;
	point.y = 0.597086;
	points << fixed << setprecision(6) << point.x << " " << point.y << " " << point.z << endl;

	//在计算坐标时，根据实际情况设置x、y、z中的一个值为定值，就是补充一个平面，将图像铺到上面
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//00575
			//double x = (double)(45.8149 - 311.146) / 568 * j / 1000 + 0.0458149;
			//00480
			//double x = (double)(679.028 - 982.262) / 568 * j / 1000 - 0.982262;
			point.x = -0.979542;
			//double z = (double)(611.243 - 401.168) / 437 * i / 1000 + 0.401168;
			double z = (double)(570.891 - 124.808) / 570 * i / 1000 + 0.124808;
			point.z = z;
			point.y = (double)(3253.41 - 2346.64) / 439 * j / 1000 + 2.34664;
			points << fixed << setprecision(6) << point.x << " " << point.y << " " << point.z << endl;
		}
	}
	points.close();
	return 0;
}