// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <iostream>

// binary search quick write exercise
int binarySearch(std::vector<int>& vec, int target) {
    
    int left=0, right = vec.size()-1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if (target == vec[mid]) return mid;
        else if (target < vec[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int mySqrt(int x) {
    if (x==0) return 0;
    if (x==1) return 1;
    unsigned int y=0;
    while (y*y < x) y++;
    return y-1;
}

int main() {
    
	return 0;
}
