# Opencv 4.0-alpha example of Face Detection using a DNN Caffe Model

## Getting Started

Visual Studio 2017 Project for Windows. Tested for Opencv 4.0-alpha 64 bits. 

### Prerequisites

At the class FaceDetector.h, there are two strings that you MUST point them to the prototxt and caffemodel files.

```
std::string ProtoDir = "deploy.prototxt";
std::string CaffeModelDir = "face_detector.caffemodel";
```

I downloaded them at:
```
https://raw.githubusercontent.com/opencv/opencv/master/samples/dnn/face_detector/deploy.prototxt
https://raw.githubusercontent.com/opencv/opencv_3rdparty/dnn_samples_face_detector_20180205_fp16/res10_300x300_ssd_iter_140000_fp16.caffemodel -> rename to face_detector.caffemodel
```

### Installing

At my environment, my opencv dir files are at

```
c:\opencv\include
c:\opencv\lib
```

Therefore you must change it at the project to your specific location at your machine.

## Acknowledgments

* Opencv
* Caffe