#include <iostream>
#include "map.hpp"

// #ifndef OPENCV_DEBUG
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
// #endif // OPENCV_DEBUG

int main(int argc, char const *argv[])
{
    std::cout << foo() << '\n';

    std::string image_path = "images/indifferent-cat.jpg";
    std::string window_name = "Indifferent cat";

    cv::Mat image = cv::imread(image_path, CV_LOAD_IMAGE_COLOR);
    
    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
    cv::imshow(window_name, image); 
    
    cv::waitKey(0);

    return 0;
}