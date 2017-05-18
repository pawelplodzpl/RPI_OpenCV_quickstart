#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat lenna;
    lenna = cv::imread("/home/pi/MySoftware/images/Lenna.png", cv::IMREAD_UNCHANGED);


    if(lenna.empty())
    {
        std::cout<<"Could not read file Lenna.png" <<std::endl;
        exit(-7);
    }

    if (!lenna.empty())
    {
        cv::imshow("Lenna", lenna);
    }

    cv::Mat videoFrame;
    cv::namedWindow("Video",cv::WINDOW_AUTOSIZE);


    cv::VideoCapture cap(0);
    if(!cap.isOpened())
    {
        std::cerr << "Could not find camera" <<std::endl;
        exit(-87);
    }



    for(;;)
    {
        cap>> videoFrame;
        if(videoFrame.empty())
        {
            std::cerr << "No camera image can be displayed" <<std::endl;
            break;
        }

        cv::imshow("Video", videoFrame);
        int key = cvWaitKey(33);
        if((key%255) > 0)
        {
            break;
        }

    }


    return 0;
}

