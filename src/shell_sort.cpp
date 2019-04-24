#include "project1.h"
#include "utils.h"
using namespace std;

void shell_sort(vector<int>& nums, const vector<int>& gaps) {
    int temp, j, n = nums.size();
    for (auto gap : gaps) {
        for (int i = gap; i < n; ++i) {
            temp = nums[i];
            for (j = i; j >= gap && nums[j - gap] > temp; --j)
                nums[j] = nums[j - gap];
            nums[j] = temp;
        }
    }
}