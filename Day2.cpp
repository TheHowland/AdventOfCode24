#include <iostream>
#include <eigen3/Eigen/Dense>
#include <algorithm>
#include <fstream>

bool isDecending(std::vector<unsigned int>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] <= v[i + 1]) {
            return false;
        }
    }
    return true;
}

bool isAscending(std::vector<unsigned int>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] >= v[i + 1]) {
            return false;
        }
    }
    return true;
}

unsigned int checkDist(std::vector<unsigned int>& v) {
    unsigned int val = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        val += static_cast<bool>((v[i]-v[i+1]) >> 2);
    }
    return val;
}

unsigned int validateSequence(std::vector<unsigned int>& v) {
    if (isAscending(v)) {
        std::ranges::reverse(v);
        return checkDist(v);
    }
    if (isDecending(v)) {
        return checkDist(v);
    }
    return 1;
}

unsigned int checkSequenceOptions(std::vector<unsigned int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::vector<unsigned int> temp = v;
        temp.erase(temp.begin() + i);

        if (!validateSequence(temp)) {
            return 0;
        }
    }
    return 1;
}

void read_file(std::vector<unsigned int>* list) {
    std::vector<unsigned int> dataLine;
    std::string line;
    unsigned int a;
    char buffer[25];

    while (std::cin.getline(buffer, 25)) {
        dataLine.clear();
        std::istringstream iss(buffer);
        while (iss >> a) {
            dataLine.push_back(a);
        }
        unsigned int returnVal = validateSequence(dataLine);
        if (returnVal) {
            returnVal = checkSequenceOptions(dataLine);
        }
        list->push_back(returnVal);
    }
}

int main(void) {
    std::vector<unsigned int> list;
    read_file(&list);

    unsigned int valid = list.size();
    for (const unsigned int i : list) {
        if (i != 0) {
            valid--;
        }
    }


    std::cout << "finished" << std::endl;
}