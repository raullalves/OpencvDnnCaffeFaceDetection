#pragma once
class FaceDetector
{
public:
	static FaceDetector * GetInstance();

	std::vector<cv::Rect> Detect(cv::Mat);
private:
	static FaceDetector * Instance;
	FaceDetector() { Initialize(); }

	void Initialize();

	std::string ProtoDir = "deploy.prototxt";
	std::string CaffeModelDir = "face_detector.caffemodel";
	std::string TorchModelDir = "face_recognition.t7";

	cv::dnn::dnn4_v20180917::Net netCaffe;

	float ths = 0.2;

	std::vector<cv::Rect> GetFaceRectsOfVectors(cv::Mat, std::vector<cv::Mat>);
};