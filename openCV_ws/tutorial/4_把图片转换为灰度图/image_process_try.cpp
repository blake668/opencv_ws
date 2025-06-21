#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // 读取图像
    Mat image = imread("map.jpg", IMREAD_GRAYSCALE);

    // 检查是否读取成功
    if (image.empty())
    {
        cout << "无法打开图像" << endl;
        return -1;
    }

    // 打印图像尺寸
    cout << "图像尺寸: " << image.rows << " x " << image.cols << endl;

    // 遍历每个像素并输出其灰度值
    for (int row = 0; row < image.rows; ++row)
    {
        for (int col = 0; col < image.cols; ++col)
        {
           // uchar pixel = image.at<uchar>(row, col);
            //cout << "像素坐标 (" << row << ", " << col << ") 的灰度值为：" << static_cast<int>(pixel) << endl;

            image.at<Vec3b>(0, 0)[0] = 255; 
        }
    }
imwrite("output.jpg", image);

    return 0;
}

