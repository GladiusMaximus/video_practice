#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
vector<Mat> loadVideo(const char* filename);

int main(int argc, char** argv) {
  cout << "Writing the first frame of " << argv[1] << " to " << argv[2] << "\n";
  vector<Mat> video = loadVideo(argv[1]);
  imwrite(argv[2], video[0]);
  return 0;
}

vector<Mat> loadVideo(const char* filename) {
  VideoCapture videoCap (filename);
  if (!videoCap.isOpened()) {
    throw "file not found";
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
