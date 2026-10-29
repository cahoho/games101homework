#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Dense>

int main(){
    Eigen::Vector2f p(2.0f, 1.0f);
    //旋转矩阵
    // cosθ -sinθ
    // sinθ cosθ

    float theta = 45.0f / 180.0f * acos(-1.0f);
    // acos(-1) = pi, 这里将角度转为弧度

    Eigen::Matrix2f R;
    R << cos(theta), -sin(theta), sin(theta), cos(theta);
    // <<是Eigen的逗号初始化器，按行优先填充

    //逆时针45
    Eigen::Vector2f p_rotated = R * p;

    std::cout<< "p_rotated: "<< p_rotated.transpose() << std::endl;
    //transpose()是Eigen的转置函数，输出时将列向量转为行向量
    
    return 0;
}

// to run:
// md build
// cd build
// cmake ..
// cmake --build .
// cd Debug
// .\name.exe
