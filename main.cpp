#include <iostream>
#include <eigen3/Eigen/Dense>
#include <algorithm>

void read_file(std::vector<int>* list1, std::vector<int>* list2) {
    int a,b;
    while(std::cin >> a >> b) {
        list1->push_back(a);
        list2->push_back(b);
    }
}

int main() {
    std::vector<int> list1;
    std::vector<int> list2;
    read_file(&list1, &list2);

    std::ranges::sort(list1);
    std::ranges::sort(list2);

    const Eigen::VectorXi vec1 = Eigen::VectorXi::Map(list1.data(), list1.size());
    const Eigen::VectorXi vec2 = Eigen::VectorXi::Map(list2.data(), list2.size());

    const unsigned int sum = (vec1 - vec2).cwiseAbs().colwise().sum()(0);
    std::cout << sum << std::endl;
}