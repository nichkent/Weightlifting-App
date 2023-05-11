//
// Created by nicho on 5/10/2023.
//

#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    // Open the default video camera
    cv::VideoCapture cap(0);

    // if not success, exit program
    if (!cap.isOpened())
    {
        std::cout << "Cannot open the video camera" << std::endl;
        std::cin.get(); //wait for any key press
        return -1;
    }

    double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
    double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    std::cout << "Resolution of the video : " << dWidth << " x " << dHeight << std::endl;

    std::string window_name = "My Camera Feed";
    cv::namedWindow(window_name); //create a window

    while (true)
    {
        cv::Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from the video camera

        //Breaking the while loop if frames cannot be read from the camera
        if (!bSuccess)
        {
            std::cout << "Video camera is disconnected" << std::endl;
            std::cin.get(); //Wait for any key press
            break;
        }

        //show the frame in the created window
        cv::imshow(window_name, frame);

        //wait for 10 ms until any key is pressed.
        //If the 'Esc' key is pressed, break the while loop.
        //If any other key is pressed, continue the loop
        //If any key is not pressed within 10 ms, continue the loop
        if (cv::waitKey(10) == 27)
        {
            std::cout << "Esc key is pressed by the user. Stopping the video" << std::endl;
            break;
        }
    }

    return 0;
}
