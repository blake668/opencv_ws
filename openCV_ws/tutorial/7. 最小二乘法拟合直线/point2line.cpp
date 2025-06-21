#include <iostream>
#include <vector>
#include <eigen3/Eigen/Dense>

// 点的结构体
struct Point {
    double x;
    double y;
};

// 将离散的点拟合成一条直线
void fitLine(const std::vector<Point>& points, double& slope, double& intercept) {
    int n = points.size();
    Eigen::MatrixXd A(n, 2);
    Eigen::VectorXd b(n);

    // 构造矩阵A和向量b
    for (int i = 0; i < n; ++i) {
        A(i, 0) = points[i].x;
        A(i, 1) = 1.0;
        b[i] = points[i].y;
    }

    // 使用最小二乘法拟合直线
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);

    slope = x[0];       // 斜率
    intercept = x[1];   // 截距
}

int main() {
    // 离散的点
    std::vector<Point> points = {{1.0, 2.0}, {2.0, 3.0}, {3.0, 4.0}, {4.0, 5.0}};

    double slope, intercept;
    fitLine(points, slope, intercept);

    std::cout << "拟合直线方程为: y = " << slope << "x + " << intercept << std::endl;

    return 0;
}

