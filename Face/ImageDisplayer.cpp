#include "stdafx.h"

ImageDisplayer* ImageDisplayer::Instance = 0;
ImageDisplayer* ImageDisplayer::GetInstance()
{
	if (Instance == 0) Instance = new ImageDisplayer();
	return Instance;
}

void ImageDisplayer::Display(cv::Mat image)
{
	cv::imshow(this->windowName, image);
	cv::waitKey(1);
}

void ImageDisplayer::Display(cv::Mat frame, std::vector<cv::Rect> rects)
{
	cv::Mat copyImage = frame.clone();

	for (auto rect : rects)
	{
		int left = rect.x;
		int right = rect.y;
		cv::rectangle(copyImage, rect, cv::Scalar(0, 255, 0));
	}

	Display(copyImage);
}

void ImageDisplayer::Initialize()
{
	cv::namedWindow(this->windowName);
}