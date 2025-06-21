#include <opencv2/opencv.hpp>

bool isDragging = false;
cv::Point startPoint;
cv::Point endPoint;
cv::Mat image = cv::imread("output.jpg");
cv::Mat overlayImage;

void onMouse(int event, int x, int y, int flags, void* userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN && !isDragging)
    {
        startPoint = cv::Point(x, y);
        isDragging = true;
    }
    else if (event == cv::EVENT_MOUSEMOVE && isDragging)
    {
        overlayImage = image.clone();  // 创建覆盖图像副本
        endPoint = cv::Point(x, y);
        cv::arrowedLine(overlayImage, startPoint, endPoint, cv::Scalar(0, 0, 255), 2, cv::LINE_AA, 0, 0.2);
    }
    else if (event == cv::EVENT_LBUTTONUP && isDragging)
    {
        overlayImage = image.clone();  // 创建覆盖图像副本
        endPoint = cv::Point(x, y);
        isDragging = false;
        cv::arrowedLine(overlayImage, startPoint, endPoint, cv::Scalar(255, 0, 0), 2, cv::LINE_AA, 0, 0.2);
        overlayImage.copyTo(image);    // 将覆盖图像副本应用到原始图像上
        overlayImage.release();        // 释放覆盖图像副本的内存
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

