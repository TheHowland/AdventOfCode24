#include <iostream>
#include <eigen3/Eigen/Dense>
#include <algorithm>
#include <chrono>

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

    const unsigned int sum = (vec1 - vec2).cwiseAbs().sum();
    std::cout << sum << std::endl;

    unsigned int total_sum = 0;
    auto ptrL1 = &list1.front();
    auto ptrL2 = &list2.front();
    auto ptrL1End = &list1.back();
    auto ptrL2End = &list2.back();

    while(ptrL1 < ptrL2End && ptrL2 < ptrL2End) {
        if (*ptrL1 > *ptrL2) {
            ptrL2++;
            continue;
        }
        if (*ptrL1 < *ptrL2) {
            ptrL1++;
            continue;
        }
        const int val = *ptrL1;
        int ptr1Count = 0;
        int ptr2Count = 0;

        while ((ptrL1 <= ptrL1End) && (*ptrL1 == val)) {
            ptr1Count++;
            ptrL1++;
        }

        while ((ptrL2 <= ptrL2End) && (*ptrL2 == val)) {
            ptr2Count++;
            ptrL2++;
        }
        total_sum += val * ptr1Count * ptr2Count;
    }
    std::cout << total_sum << std::endl;
    return 0;

}