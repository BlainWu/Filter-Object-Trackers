//
//
////
//
//
//
//
//
//
//

//
//
//
//
////
//
//
//
//
//
//
//

//
//
//
//
////
//
//
//
//
//
//
//

//
//
//
//
////
//
//
//
//
//
//
//

//
////
////
//////
////
////
////
////
////
////
////
//
////
////
//
//
////
//
//
//
//
//
//
//

//
//
//
//
////
//
//
//
//
//
//
//

//
//
//
//
////
//
//
//
//
//
//
//

//
//
//
//
////
//
//
//
//
//
//
//

//
//
//
//
////
//
//
//
//
//
//
//

//
//






#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main( int argc, char** argv ){
    // 初始化参数
    int FPS = 35,delay = 1000/FPS,method_select;
    bool isTracking;
    Rect2d roi;
    Ptr<Tracker> tracker;
    Mat frame;
    //Ptr<Tracker> tracker;
     cout <<"选择算法，输入算法序号"<<endl<<
    "1.BOOSTING"<<endl<<
    "2.MIL"<<endl<<
    "3.KCF"<<endl<<
    "4.CSRT"<<endl<<
    "5.MOSSE"<<endl<<
    "6.GoTurn"<<endl<<
    "7.MedianFlow"<<endl;
    do{
        cin >> method_select;
    }while(method_select>7||method_select<1);

    // 选择算法
   switch (method_select){
        case 1 :{
            cout<<"已选择Boosting"<<endl;
            tracker= TrackerBoosting::create();
            break;
        }
        case 2 :{
            cout<<"已选择MIL"<<endl;
            tracker= TrackerMIL::create();
            break;
        }
        case 3 :{
            cout<<"已选择KCF"<<endl;
            tracker = TrackerKCF::create();
            break;}

        case 4 :{
            cout<<"已选择CSRT"<<endl;
            tracker= TrackerCSRT::create();
            break;
        }
        case 5 :{
            cout<<"已选择MOSSE"<<endl;
            tracker= TrackerMOSSE::create();
            break;
        }
        case 7 :{
           cout<<"已选择MediaFlow"<<endl;
           tracker= TrackerMedianFlow::create();
           break;
       }
        default:{
            cout<<"没有正确选择算法"<<endl;
            return 0;
        }
    }
    // 设置测试视频
    std::string video = "../../battle-jet.mp4";
    VideoCapture cap(video);
    // 获得初始bounding box
    cap >> frame;
    roi = selectROI("tracker",frame);
    //如果没有选择方框则直接退出
    if(roi.width==0 || roi.height==0)
        return 0;
    // initialize the tracker
    tracker->init(frame,roi);

    while(cap.isOpened()){
        // get frame from the video
        cap >> frame;
        // stop the program if no more images7

        if(frame.rows==0 || frame.cols==0)
            break;
        // update the tracking result
        isTracking=tracker->update(frame,roi);
        if(isTracking)
            putText(frame,"Tracking",Point(30,30),FONT_HERSHEY_SIMPLEX, 1.4, Scalar(0,255,0), 2);
        else
            putText(frame,"Lost",Point(30,30),FONT_HERSHEY_SIMPLEX, 1.4, Scalar(0,0, 255), 2);
        // draw the tracked object
        rectangle( frame, roi, Scalar( 255, 0, 0 ), 2, 1 );
        // show image with the tracked object
        imshow("tracker",frame);
        //quit on ESC button
        waitKey(delay);
        if(waitKey(1)==27)break;
    }
    return 0;
}