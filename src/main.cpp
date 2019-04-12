#include <iostream>
#include "map.hpp"

#if OPENCV_DEBUG
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#endif // OPENCV_DEBUG


#define UNUSED(x) (void)(x)


int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    std::cout << foo() << '\n';

    std::string image_path = "images/indifferent-cat.jpg";
    std::string window_name = "Indifferent cat";

#if OPENCV_DEBUG

    cv::Mat image = cv::imread(image_path, cv::IMREAD_COLOR);
    
    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
    cv::imshow(window_name, image); 
    
    cv::waitKey(0);

#endif // OPENCV_DEBUG

    return 0;
}
