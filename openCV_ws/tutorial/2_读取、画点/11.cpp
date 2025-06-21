//g++ 11.cpp -o 11 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc
//读取一张图片，获得此图片的像素矩阵
//获得此像素矩阵的宽和高
//在此图片上标记一些坐标点

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;

int main() {
    //创建一个窗口
    //cv::namedWindow("Map", cv::WINDOW_NORMAL) 是 OpenCV 中用于创建一个显示图像的窗口。
    //具体而言，这个函数有两个参数：
    //第一个参数是窗口的名称，这里使用 "Map"。
    //第二个参数是可选的窗口标志，指定窗口的行为。在这里使用 cv::WINDOW_NORMAL 表示创建一个可调整大小的窗口。
    //使用 cv::namedWindow 创建窗口后，您可以使用其他 OpenCV 函数来显示图像、绘制图形以及处理用户交互等操作。
    cv::namedWindow("Map", cv::WINDOW_NORMAL);

    // 读取地图图像文件
    cv::Mat map = cv::imread("map.jpg");
    int width = map.cols;
    int height = map.rows;
    
    //cout<< "width with "<<width;
    //cout<< "height with "<<height;

    cout<< "width with "<<width<<"\n";
    cout<< "height with "<<height<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////像素处理////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //创建了一个 std::vector<cv::Point> 类型的变量 coordinates，并向其中添加了三个 cv::Point 对象，分别表示不同的坐标点。
    //然后，通过使用 cv::circle 函数在地图上绘制圆来标记每个坐标点。
    //循环遍历 coordinates 向量中的每个点，并使用 cv::circle 绘制一个半径为 5 的红色实心圆。
    //此处假设您已经加载了地图图像，并将其命名为 map
    std::vector<cv::Point> coordinates;
    coordinates.push_back(cv::Point(100, 100));
    coordinates.push_back(cv::Point(200, 300));
    coordinates.push_back(cv::Point(400, 200));

    //在地图上标记
    //for (const auto& point : coordinates) 是一个范围循环（range-based loop），用于遍历 coordinates 向量中的每个元素，并将其赋值给变量 point。
    //在循环的每次迭代中，point 将被绑定到 coordinates 中的一个元素，以便可以对其进行操作。
    //通过使用 const auto&，您确保 point 是一个常量引用，即在循环内部不能修改 point 的值。
    /*
    for (const auto& point : coordinates) {
        std::cout << "x: " << point.x << ", y: " << point.y << std::endl;
    }
    */
    //cv::circle(map, point, 5, cv::Scalar(0, 0, 255), -1) 是 OpenCV 中的一个函数调用，用于在图像上绘制一个圆。
    //参数解释如下：
    //  map：表示要在其上绘制圆的图像矩阵。
    //  point：表示圆心的坐标点。
    //  5：表示圆的半径。
    //  cv::Scalar(0, 0, 255)：表示绘制圆时所使用的颜色。在这里，我们使用 Scalar 类型创建了一个红色（B=0, G=0, R=255）的颜色对象。
    //  -1：表示绘制实心圆，填充圆内的区域。负数：实心 正数：空心，且数值为线宽
    //因此，cv::circle(map, point, 5, cv::Scalar(0, 0, 255), -1) 的作用是在 map 图像上以 point 为圆心，半径为 5，绘制一个红色的实心圆。
    for (const auto& point : coordinates) {
        cv::circle(map, point, 10, cv::Scalar(0, 0, 255), 2);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // 显示更新后的地图
    cv::imshow("Map", map);

    // 等待按下任意键后关闭窗口
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}


//为什么？？
