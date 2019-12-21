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
		Mat frame;
		cam >> frame;

		// Modify image
		cvtColor(frame, frame, COLOR_BGR2GRAY);

		// Display image
		imshow("Camera Feed", frame);

		keyPress = waitKey(1);
		if (keyPress % 256 == 27) {
			cout << "Escape pressed.\nExiting program..." << endl;
			break;
		}
	}

	cam.release();
	destroyAllWindows();
}
