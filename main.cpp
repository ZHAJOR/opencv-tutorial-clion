#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main(int argc, char** argv)
{
    cv::VideoCapture cap(0);
    if(!cap.isOpened())
        return -1;


    cv::Mat edges;
    cv::namedWindow("edges",1);
    for(;;)
    {
        cv::Mat frame;
        cap >> frame; // get a new frame from camera
        cv::cvtColor(frame, edges, CV_BGR2GRAY);
        cv::GaussianBlur(edges, edges, cv::Size(7,7), 1.5, 1.5);
        cv::Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if(cv::waitKey(30) >= 0) break;
    }
    return 0;
}
