#include <opencv2/opencv.hpp>
#include "cvlibs.h"

int main(void)
{
	//---------------------
	//���[�h
	cv::Mat_<cv::Vec3b> img_rgb = cv::imread("img000.png");

	//�Z�[�u
	cv::imwrite("output1.png", img_rgb);

	//---------------------
	int i = 100;
	int j = 200;

	//��f(i, j)��rgb�l��ϐ��ɑ��
	cv::Vec3b rgb = img_rgb(j, i);

	std::cout << rgb << std::endl;

	//��f(i, j)��r�l��ϐ��ɑ��
	uchar r = img_rgb(j, i)(0);

	std::cout << int(r) << std::endl;;

	//�摜(i, j)�ɐF(0, 100, 200)����
	img_rgb(j, i) = cv::Vec3b(0, 100, 200);

	cv::imwrite("output2.png", img_rgb);

	//---------------------
	//cv::Mat_�̏������@�\
	cv::Mat_<double> mat1 = (cv::Mat_<double>(3, 2) <<
		1.0, 2.0,
		3.0, 4.0,
		5.0, 6.0);

	std::cout << mat1 << std::endl;

	//cv::Mat��cv::Mat_����ď������\
	cv::Mat mat2 = (cv::Mat_<double>(3, 2) <<
		1.2, 2.3,
		3.4, 4.5,
		5.6, 6.7);

	std::cout << mat2 << std::endl;

	//---------------------6
	//data�ɒ�����
	cv::Mat_<cv::Vec3b> a = cv::imread("img000.png");	
	a.data[0] = 0;
	a.data[1] = 0;
	a.data[2] = 255;

	cv::imwrite("output3.png", img_rgb);
	cv::waitKey(0);
}