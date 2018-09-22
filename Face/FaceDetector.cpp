#include "stdafx.h"
FaceDetector * FaceDetector::Instance = 0;
FaceDetector * FaceDetector::GetInstance()
{
	if (Instance == 0) Instance = new FaceDetector();
	return Instance;
}

std::vector<cv::Rect> FaceDetector::Detect(cv::Mat image)
{
	cv::Mat frameBgr;
	std::vector<cv::Rect> rects;
	cv::cvtColor(image, frameBgr, cv::COLOR_RGBA2BGR);
	auto blob = cv::dnn::blobFromImage(frameBgr, 3, cv::Size(300, 300), cv::Scalar(104, 177, 123), false);
	this->netCaffe.setInput(blob);

	std::vector<cv::Mat> outs;
	this->netCaffe.forward(outs);
	
	return GetFaceVectorOfRects(image, outs);
}

void FaceDetector::Initialize()
{
	this->netCaffe = cv::dnn::readNetFromCaffe(this->ProtoDir, this->CaffeModelDir);
}

std::vector<cv::Rect> FaceDetector::GetFaceVectorOfRects(cv::Mat image, std::vector<cv::Mat> outs)
{
	std::vector<cv::Rect> rects;
	
	float* data = (float*)outs[0].data;

	for (size_t i = 0; i < outs[0].total(); i += 7)
	{
		float confidence = data[i + 2];
		if (confidence < this->ths) continue;
		int left = (int)(data[i + 3] * image.cols);
		int top = (int)(data[i + 4] * image.rows);
		int right = (int)(data[i + 5] * image.cols);
		int bottom = (int)(data[i + 6] * image.rows);
		int width = right - left + 1;
		int height = bottom - top + 1;
		rects.push_back(cv::Rect(left, top, width, height));
	}

	return rects;
}