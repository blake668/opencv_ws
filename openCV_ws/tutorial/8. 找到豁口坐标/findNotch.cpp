#include <iostream>
#include <cmath>
#include <vector>

struct Point {
    double x;
    double y;
};

Point findNotch(const std::vector<Point>& points) {
    int n = points.size();

    // 计算均值
    double mean_x = 0.0;
    double mean_y = 0.0;
    for (const Point& p : points) {
        mean_x += p.x;
        mean_y += p.y;
    }
    mean_x /= n;
    mean_y /= n;

    // 计算相对于均值的差值
    std::vector<double> dx(n);
    std::vector<double> dy(n);
    for (int i = 0; i < n; ++i) {
        dx[i] = points[i].x - mean_x;
        dy[i] = points[i].y - mean_y;
    }

    // 计算斜率和截距
    double slope = 0.0;
    double intercept = 0.0;
    double sum_dx_squared = 0.0;
    for (int i = 0; i < n; ++i) {
        slope += dx[i] * dy[i];
        sum_dx_squared += dx[i] * dx[i];
    }
    slope /= sum_dx_squared;
    intercept = mean_y - slope * mean_x;

    // 找到豁口点的坐标
    double max_distance = 0.0;
    Point notch;
    for (int i = 0; i < n; ++i) {
        double distance = std::abs(slope * points[i].x - points[i].y + intercept) / std::sqrt(slope * slope + 1);
        if (distance > max_distance) {
            max_distance = distance;
            notch = points[i];
        }
    }

    return notch;
}

int main() {
    std::vector<Point> points = {{1.0, 2.5}, {2.0, 4.0}, {3.0, 6.0}, {4.0, 8.5}, {5.0, 10.0}};

    Point notch = findNotch(points);

    double slope = (notch.y - points[0].y) / (notch.x - points[0].x);
    double intercept = notch.y - slope * notch.x;

    std::cout << "拟合直线方程：y = " << slope << " * x + " << intercept << std::endl;
    std::cout << "豁口点坐标：(" << notch.x << ", " << notch.y << ")" << std::endl;

    return 0;
}

