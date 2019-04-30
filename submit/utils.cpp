#include "utils.h"

void swap(int &i, int&j) {
    int temp = i;
    i = j;
    j = temp;
}

int min(int i, int j) {
    return i < j ? i : j;
}

int max(int i, int j) {
    return i > j ? i : j;
}

bool is_sorted(const vector<int> &nums) {
    int n = nums.size();
    if (n < 2)
        return true;
    for (int i = 1; i < n; ++i) {
        if (nums[i - 1] > nums[i])
            return false;
    }
    return true;
}

void set_vector(vector<int> &nums, const vector<int>& src) {
    nums.clear();
    for (auto s: src)
        nums.push_back(s);
}

int randint(int lb, int ub) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    if (lb < ub) {
        uniform_int_distribution<int> range(lb, ub);
        return range(gen);
    } else
        return lb;
}

void reverse(vector<int> & nums) {
    int n = nums.size();
    for (int i = 0; i < n/2; ++i) {
        swap(nums[i], nums[n - 1 - i]);
    }
}

vector<int> get_shell_sort_gaps(int n, int seq) {
    vector<int> gaps;
    switch (seq) {
    case 0:
        for (int i = n / 2; i > 0; i /= 2)
            gaps.push_back(i);
        break;
    case 1:
        for (int i = (int) n / 2.2; i > 0; i = (int) i / 2.2)
            gaps.push_back(i);
        break;
    case 2:
        for (int i = (int) n / 2.25; i > 0; i = (int) i / 2.25)
            gaps.push_back(i);
        gaps.push_back(1);
        break;
    case 3:
        if (n > 701)
            gaps.push_back(701);
        if (n > 301)
            gaps.push_back(301);
        if (n > 132)
            gaps.push_back(132);
        if (n > 57)
            gaps.push_back(57);
        if (n > 23)
            gaps.push_back(23);
        if (n > 10)
            gaps.push_back(10);
        if (n > 4)
            gaps.push_back(4);
        gaps.push_back(1);
        break;
    case 4:
        if (n > 1391376)
            gaps.push_back(1391376);
        if (n > 463792)
            gaps.push_back(463792);
        if (n > 198768)
            gaps.push_back(198768);
        if (n > 86961)
            gaps.push_back(86961);
        if (n > 33936)
            gaps.push_back(33936);
        if (n > 13776)
            gaps.push_back(13776);
        if (n > 4592)
            gaps.push_back(4592);
        if (n > 1968)
            gaps.push_back(1968);
        if (n > 861)
            gaps.push_back(861);
        if (n > 336)
            gaps.push_back(336);
        if (n > 112)
            gaps.push_back(112);
        if (n > 48)
            gaps.push_back(48);
        if (n > 21)
            gaps.push_back(21);
        if (n > 7)
            gaps.push_back(7);
        if (n > 3)
            gaps.push_back(3);
        if (n > 1)
            gaps.push_back(1);
        break;
    default:
        if (n > 86961)
            gaps.push_back(86961);
        if (n > 33935)
            gaps.push_back(33935);
        if (n > 13776)
            gaps.push_back(13776);
        if (n > 4592)
            gaps.push_back(4592);
        if (n > 1969)
            gaps.push_back(1969);
        if (n > 861)
            gaps.push_back(861);
        if (n > 336)
            gaps.push_back(336);
        if (n > 111)
            gaps.push_back(111);
        if (n > 47)
            gaps.push_back(47);
        if (n > 22)
            gaps.push_back(22);
        if (n > 7)
            gaps.push_back(7);
        if (n > 3)
            gaps.push_back(3);
        if (n > 1)
            gaps.push_back(1);
        break;
    }
    return gaps;
}

vector<int> get_annealing_sort_temps(int n, int seq) {
    vector<int> temps;
    int phase;
    switch (seq) {
    case 0:
        phase = n;
        for (int i = 0; i < phase; ++i)
            temps.push_back(0);
        break;
    case 1:
        phase = n / 2;
        for (int i = 0; i < phase / 3; ++i)
            temps.push_back(n);
        for (int i = 0; i < phase / 3; ++i)
            temps.push_back(log(n));
        for (int i = 0; i < phase / 3; ++i)
            temps.push_back(0);
        break;
    case 2:
        phase = n / 2;
        for (int i = 0; i < phase / 3; ++i)
            temps.push_back(n);
        for (int i = 0; i < phase / 3; ++i)
            temps.push_back(log(n));
        for (int i = 0; i < phase / 3; ++i)
            temps.push_back(0);
        break;
    case 3: case 4: 
    default:
        phase = n / 2;
        for (int i = 0; i < phase / 4; ++i)
            temps.push_back(n);
        for (int i = 0; i < phase / 2; ++i)
            temps.push_back(log(n));
        for (int i = 0; i < phase / 4; ++i)
            temps.push_back(0);
        break;
    }
    return temps;
}

vector<int> get_annealing_sort_reps(int n, int seq) {
    vector<int> reps;
    int phase;
    switch (seq) {
    case 0:
        phase = n;
        for (int i = 0; i < phase; ++i)
            reps.push_back(1);
        break;
    case 1:
        phase = n / 2;
        for (int i = 0; i < phase / 3; ++i)
            reps.push_back(2);
        for (int i = 0; i < phase / 3; ++i)
            reps.push_back(2);
        for (int i = 0; i < phase / 3; ++i)
            reps.push_back(1);
        break;
    case 2:
        phase = n / 2;
        for (int i = 0; i < phase / 3; ++i)
            reps.push_back(2);
        for (int i = 0; i < phase / 3; ++i)
            reps.push_back(1);
        for (int i = 0; i < phase / 3; ++i)
            reps.push_back(1);
        break;
    case 3:
        phase = n / 2;
        for (int i = 0; i < phase / 4; ++i)
            reps.push_back(2);
        for (int i = 0; i < phase / 2; ++i)
            reps.push_back(1);
        for (int i = 0; i < phase / 4; ++i)
            reps.push_back(1);
        break;
    case 4:
    default:
        phase = n / 2;
        for (int i = 0; i < phase; ++i)
            reps.push_back(1);
        break;
    }

    return reps;
}