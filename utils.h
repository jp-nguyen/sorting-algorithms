#include <iostream>
using namespace std;

inline void swap(int &i, int&j) {
    int temp = i;
    i = j;
    j = temp;
}