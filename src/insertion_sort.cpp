#include "../include/project1.h"
#include "../include/utils.h"

void insertion_sort(std::vector<int>& nums) {
    int key, j, n = nums.size();

    for (int i = 1; i < n; ++i) {
        key = nums[i];
        j = i - 1;
        while (j >= 0 && key < nums[j]) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
    }
}