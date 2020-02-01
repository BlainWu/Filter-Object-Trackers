/*
 * 2020 / 02 /01
 * Blain Wu created
 * github:https://github.com/BlainWu/Filter-Object-Trackers
*/
#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void featureExtractor(const Mat img,const Rect roi,Mat & feature);

int main( int argc, char** argv ){
    //声明变量
    Rect2d roi;
    Mat frame;

    TrackerKCF::Params param;
    param.
}