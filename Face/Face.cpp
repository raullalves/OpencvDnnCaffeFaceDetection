// Face.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	cv::VideoCapture cap;
	if (!cap.open(0))
		return 1;

	for (;;)
	{
		cv::Mat frame;
		cap >> frame;
		if (frame.empty()) break; 

		auto rects = FaceDetector::GetInstance()->Detect(frame);
		ImageDisplayer::GetInstance()->Display(frame, rects);
	}

	return 0;
}

