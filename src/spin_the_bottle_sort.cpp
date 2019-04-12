#include "../include/project1.h"
#include "../include/utils.h"

void spin_the_bottle_sort(std::vector<int>& nums) {
    int s, n = nums.size();

    while (!is_sorted(nums)) {
        for (int i = 0; i < n; ++i) {
            s = randint(0, n - 2);
            s += (s >= i);
            if ((i < s && nums[i] > nums[s]) || (i > s && nums[i] < nums[s]))
                swap(nums[i], nums[s]);
        }
    }
}