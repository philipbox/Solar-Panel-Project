#include <iostream>
#include <fstream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/stitching.hpp>
#include <vector>

using namespace std;
using namespace cv;

bool try_use_gpu = false;
Stitcher::Mode mode = Stitcher::PANORAMA;
vector<Mat> imgs;

void main()
{
	Stitcher s = Stitcher::createDefault();

	Mat input1, input2, input3;
	input1 = imread("a1.png", CV_LOAD_IMAGE_COLOR);
	input2 = imread("a2.png", CV_LOAD_IMAGE_COLOR);
	input3 = imread("a3.png", CV_LOAD_IMAGE_COLOR);

	vector<Mat> VectorInput;
	VectorInput.push_back(input1);
	VectorInput.push_back(input2);
	VectorInput.push_back(input3);

	Mat MatResult;

	int r = s.stitch(VectorInput, MatResult);

	if (r == s.Status::OK)
	{
		namedWindow("stitch", CV_WINDOW_NORMAL | CV_GUI_EXPANDED);
		imshow("stitch", MatResult);
		waitKey(0);
	}
	else
	{

	}
}