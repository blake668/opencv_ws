//g++ corner.cpp -o 11 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
#include <opencv2/opencv.hpp>

int main() {
    // 读取图像
    cv::Mat image = cv::imread("plugin.png");

    // 转换为灰度图像
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // 检测拐角
    std::vector<cv::Point2f> corners;
    cv::goodFeaturesToTrack(grayImage, corners, 100, 0.01, 10);

    // 绘制拐角
    for (const auto& point : corners) {
        cv::circle(image, point, 5, cv::Scalar(0, 0, 255), cv::FILLED);
    }

    // 显示图像
    cv::imshow("Corners", image);
    cv::waitKey(0);

    return 0;
}

