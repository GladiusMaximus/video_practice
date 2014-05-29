#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

vector<Mat> getFrames(const char* filename) {
  VideoCapture videoCap (filename);
  if (!videoCap.isOpened()) {
    cerr << "Input video file '"<< filename << "' not found!\n";
  }
  vector<Mat> videoVector;
  videoVector.reserve(500);

  unsigned int idx = 0;
  while (true) {
    Mat frame;
    videoCap >> frame;
    if (frame.empty()) {
      break;
    }
    videoVector.push_back(frame);
  }

  videoVector.shrink_to_fit();
  return videoVector;
}

void show(const Mat frame, const char* filename) {
  bool res = imwrite(filename, frame);
  if (!res) {
    cerr << "Writting to '" << filename << "' failed!\n";
  }
}

Mat toGray(const Mat inputFrame) {
  Mat ret;
  cvtColor(inputFrame, ret, CV_BGR2GRAY);
  return ret;
}

Mat getBG(const vector<Mat> input) {
  Mat out;
  Mat I = input[0];
  for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it,i++) {
    
  }
}

int main(int argc, char** argv) {
  return 0;
}
