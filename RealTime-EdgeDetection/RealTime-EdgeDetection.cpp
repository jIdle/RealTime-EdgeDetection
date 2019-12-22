// RealTime-EdgeDetection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	int keyPress = 0;
	VideoCapture cam(0);
	namedWindow("Camera Feed");
	if (!cam.isOpened()) {
		cout << "No default camera. Exiting program..." << endl;
		exit(EXIT_FAILURE);
	}

	for (;;) {
		// Retrieve image from camera
		Mat frame, frame2;
		Mat gradX, gradY;
		Mat result;
		cam >> frame;

		// Modify image
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		GaussianBlur(frame, frame, Size(9,9), 2);
		//Sobel(frame, gradX, -1, 1, 0);
		//Sobel(frame, gradY, -1, 0, 1);
		//addWeighted(abs(gradX), 0.5, abs(gradY), 0.5, 0, result);
		Laplacian(frame, result, -1, 5);

		// Display image
		imshow("Camera Feed", result);

		keyPress = waitKey(1);
		if (keyPress % 256 == 27) {
			cout << "Escape pressed.\nExiting program..." << endl;
			break;
		}
	}

	cam.release();
	destroyAllWindows();
}
