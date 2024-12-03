#include <iostream>
#include <eigen3/Eigen/Dense>
#include <algorithm>

void read_file(std::vector<int>* list) {
    int a,b,c,d,e;
    int val;
    while(std::cin >> a >> b >> c >> d >> e) {
      val = 1;
      if ((a-b) > 0 && (b-c) > 0 && (c-d) > 0 && (d-e) > 0) {
          val = ((unsigned int)(a-b) >> 2) + ((unsigned int)(b-c) >> 2) + ((unsigned int)(c-d) >> 2) + ((unsigned int)(d-e) >> 2);
      }
      if ((b-a) > 0 && (c-b) > 0 && (d-c) > 0 && (e-d) > 0) {
          val = ((unsigned int)(b-a) >> 2) + ((unsigned int)(c-b) >> 2) + ((unsigned int)(d-c) >> 2) + ((unsigned int)(e-d) >> 2);
      }
      list->push_back(val);
    }
}

int main(void) {
    std::vector<int> list;
    read_file(&list);

    unsigned int all = list.size();
    int unsafe = 0;
    for (int i = 0; i < list.size(); i++) {
      if (list[i] != 0){
          all--;
      }
    }
    int result = all-unsafe;
    std::cout << result << std::endl;
}