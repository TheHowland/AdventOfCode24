#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <bits/fs_dir.h>
#include <eigen3/Eigen/Dense>

void read_txt(Eigen::Matrix<int, Eigen::Dynamic, 1>* vec1, Eigen::Matrix<int, Eigen::Dynamic, 1>* vec2) {
    int a ,b;
    unsigned int len = 1;
    while ((std::cin >> a >> b)) {
        vec1->resize(len);
        vec1[len] << a;
        vec2[len] << b;
        len++;
    }
}

unsigned int calc_distance(Eigen::Matrix<int, Eigen::Dynamic, 1>* vec1, Eigen::Matrix<int, Eigen::Dynamic, 1>* vec2) {
    std::ranges::sort(std::begin(*vec1), std::end(*vec1), std::less<int>());
    std::ranges::sort(std::begin(*vec1), std::end(*vec1), std::less<int>());

    unsigned int dist_sum = 0;
    Eigen::Matrix<int, Eigen::Dynamic, 1> sum_vec;
    sum_vec.resize(vec1->rows());
    sum_vec = vec1 - vec2;

    return dist_sum;
}


int main() {
    Eigen::Matrix<int, Eigen::Dynamic, 1> vec1;
    Eigen::Matrix<int, Eigen::Dynamic, 1> vec2;

    read_txt(&vec1, &vec2);

    const unsigned int dist_sum = calc_distance(&vec1, &vec2);
    std::cout << dist_sum << std::endl;


    return 0;
}
