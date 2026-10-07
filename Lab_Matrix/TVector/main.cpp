#include <iostream>
#include "TVector.h"

int main() {
    TVector<int> my_vec(8);
    int val = 1;

    for (TVector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++) {
        *it = val++;
    }

    const TVector<int>& vec = my_vec;
    for (TVector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    return 0;
}