//g++ click_place_circle.cpp -o 11 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
#include <opencv2/opencv.hpp>

std::vector<cv::Point> points;  // 存储点击处的坐标
cv::Point point;
cv::Mat image = cv::imread("output.jpg");
void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN)  // 当左键被点击时
    {
        point.x = x;
        point.y = y;
        points.push_back(point);  // 将坐标添加到向量中
        
        // 在控制台输出点击处的坐标
        std::cout << "Clicked at: (" << x << ", " << y << ")" << std::endl;
    }
    cv::circle(image, point, 10, cv::Scalar(0, 0, 255), 2);
}

int main()
{
      // 加载图像，将其替换为你的图像路径
    
    cv::namedWindow("Image", cv::WINDOW_NORMAL);
    cv::setMouseCallback("Image", onMouse);  // 设置鼠标事件回调函数
    
    while (true)
    {
        cv::imshow("Image", image);
        
        int key = cv::waitKey(1);
        if (key == 27)  // 当按下 ESC 键时退出程序
            break;
        
    }
    
    cv::destroyAllWindows();
    
    return 0;
}

