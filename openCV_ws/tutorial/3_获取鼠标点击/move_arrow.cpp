//g++ move_arrow.cpp -o 22 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc

//存在问题，没做到每一个循环都清除一下之前的箭头
#include <opencv2/opencv.hpp>

bool isDragging = false;
cv::Point startPoint;
cv::Point endPoint;
cv::Mat image = cv::imread("output.jpg");
void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN && !isDragging)
    {
        startPoint = cv::Point(x, y);
        isDragging = true;
    }
    else if (event == cv::EVENT_MOUSEMOVE && isDragging)
    {
        endPoint = cv::Point(x, y);
        cv::arrowedLine(image, startPoint , endPoint, cv::Scalar(0, 0, 255), 2, cv::LINE_AA, 0, 0.2);
    }
    else if (event == cv::EVENT_LBUTTONUP && isDragging)
    {
        endPoint = cv::Point(x, y);
        isDragging = false;
        cv::arrowedLine(image, startPoint , endPoint, cv::Scalar(255, 0, 0), 2, cv::LINE_AA, 0, 0.2);
    }
}

int main()
{
    
    cv::namedWindow("Image", cv::WINDOW_NORMAL);
    cv::setMouseCallback("Image", onMouse);

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

