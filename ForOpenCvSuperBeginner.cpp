#include <opencv2/opencv.hpp>
#include "cvlibs.h"

int main(void)
{
	//---------------------
	//ロード
	cv::Mat_<cv::Vec3b> img_rgb = cv::imread("img000.png");

	//セーブ
	cv::imwrite("output1.png", img_rgb);

	//---------------------
	int i = 100;
	int j = 200;

	//画素(i, j)のrgb値を変数に代入
	cv::Vec3b rgb = img_rgb(j, i);

	std::cout << rgb << std::endl;

	//画素(i, j)のr値を変数に代入
	uchar r = img_rgb(j, i)(0);

	std::cout << int(r) << std::endl;;

	//画像(i, j)に色(0, 100, 200)を代入
	img_rgb(j, i) = cv::Vec3b(0, 100, 200);

	cv::imwrite("output2.png", img_rgb);

	//---------------------
	//cv::Mat_の初期化機能
	cv::Mat_<double> mat1 = (cv::Mat_<double>(3, 2) <<
		1.0, 2.0,
		3.0, 4.0,
		5.0, 6.0);

	std::cout << mat1 << std::endl;

	//cv::Matもcv::Mat_を介して初期化可能
	cv::Mat mat2 = (cv::Mat_<double>(3, 2) <<
		1.2, 2.3,
		3.4, 4.5,
		5.6, 6.7);

	std::cout << mat2 << std::endl;

	//---------------------6
	//dataに直書き
	cv::Mat_<cv::Vec3b> a = cv::imread("img000.png");	
	a.data[0] = 0;
	a.data[1] = 0;
	a.data[2] = 255;

	cv::imwrite("output3.png", img_rgb);
	cv::waitKey(0);
}