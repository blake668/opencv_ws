//g++ show_word_on_image.cpp -o 11 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
#include <opencv2/opencv.hpp>
#include <string>
int main() {
    // 加载图像
    cv::Mat image = cv::imread("output.jpg");
    double a = 0.9;
    std::string myString = std::to_string(a);
    
    if (image.empty()) {  // 检查图像是否加载成功
        std::cout << "无法加载图像文件" << std::endl;
        return -1;
    }

    // 在图像上绘制文字
    cv::putText(image, myString, cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 255, 0), 1);

    // 显示图像
    cv::imshow("Image with Text", image);

    // 等待按下任意键后退出程序
    cv::waitKey(0);

    return 0;
}
