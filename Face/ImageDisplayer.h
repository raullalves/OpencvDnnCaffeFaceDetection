#pragma once
class ImageDisplayer
{
public:
	static ImageDisplayer * GetInstance();
	void Display(cv::Mat, std::vector<cv::Rect>);
	
private:
	static ImageDisplayer * Instance;
	ImageDisplayer() { Initialize(); }
	void Initialize();

	void Display(cv::Mat);

	std::string windowName = "Frame from Camera";
};