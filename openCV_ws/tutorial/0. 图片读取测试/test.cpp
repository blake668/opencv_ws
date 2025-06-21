//g++ test.cpp -o 11 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

int main() {

    cv::namedWindow("testMap", cv::WINDOW_NORMAL);
    cv::Mat map = cv::imread("/home/zhangzh6/catkin_ws_1/src/experiments/no1_drive_a_circle/image/output.jpg");
    if (map.empty()) {  
        cout<<"cannot load the image \n";
        return 0;
    }
    int width = map.cols;
    int height = map.rows;
    cout<< "width with "<<width<<"\n";
    cout<< "height with "<<height<<"\n";


    cv::imshow("Map", map);

    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}


