//#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "lsd.h"

int cnvDouble(cv::Mat *in, double out[]) {
	int y;
	for (int i=0; i<in->rows; i++) {
		y = i*in->cols;
		for (int j=0; j<in->cols; j++) {
			out[j+y] = ((double)in->data[j+y]);
		}
	}
	return 0;
}

int cnvcvMat(cv::Mat *out, double in[]) {
	int y;
	for (int i=0; i<out->rows; i++) {
		y = i*out->cols;
		for (int j=0; j<out->cols; j++) {
			out->data[j+y] = ((unsigned char)in[j+y]);
		}
	}
	return 0;
}

int main(){
	cv::Mat in, img;
	int n=0;
	double *out;
	double dst[307200];
	cv::VideoCapture cap(0);
	if (!cap.isOpened())	return -1;
	
	cv::namedWindow("dst");

	while(1) {
		cap >> in;
		cv::cvtColor(in, img, CV_BGR2GRAY);
		cnvDouble(&img, dst);

		out = lsd(&n, dst, img.cols, img.rows);

		for (int i=0; i<n; i++) {
			cv::line(in,cv::Point( (int)out[7*i+0] , (int)out[7*i+1] ),cv::Point((int)out[7*i+2],(int)out[7*i+3]),cv::Scalar( 0, 0, 255 ),1,0);
		}
		cv::imshow("dst",in);

		if (cv::waitKey(100)!=-1)	break;
	}
	
	return 0;
}

