//g++ openCV_try.cpp -o 11 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    //创建一个 500x500 像素的表格
    //创建了一个名为table的cv::Mat对象，它是一个大小为500x500像素的图像，具有3个通道（B、G和R）。初始时，图像中的所有像素都被设置为白色（RGB值为255, 255, 255）。
    //cv::Mat是OpenCV中表示图像数据的类。在这里，通过指定图像的大小和通道数，以及初始像素值来创建了一个table对象。
    //500, 500表示图像的宽度和高度为500像素。
    //CV_8UC3表示图像的数据类型为8位无符号整型（每个通道的像素值范围为0到255），通道数为3（彩色图像）。
    //cv::Scalar(255, 255, 255)表示初始像素值为白色（RGB值为255, 255, 255）。
    //就创建了一个大小为500x500像素的空白图像，可以在其中进行绘图操作。
    cv::Mat table(50, 50, CV_8UC3, cv::Scalar(255, 255, 255)); // 白色背景

    // 在表格上绘制一些图案
    //cv::rectangle(table, cv::Rect(10, 10, 80, 80), cv::Scalar(0, 0, 255), -1); // 矩形
    //cv::circle(table, cv::Point(50, 50), 25, cv::Scalar(0, 255, 0), -1); // 圆形
    //cv::line(table, cv::Point(80, 20), cv::Point(20, 80), cv::Scalar(255, 0, 0), 2); // 直线

    // 输出表格为图像
    cv::imwrite("output.jpg", table);
    cv::imwrite("output.png",table);
    cv::imwrite("output.pgm",table);

    return 0;
}

