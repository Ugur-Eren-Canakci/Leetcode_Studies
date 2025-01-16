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
    //while (y*y < x) y++;
    return y-1;
}


void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    if (m==0) nums1.swap(nums2);
    else if (n==0) {}
    else {
        for (int i=0; i<n; i++) {
            for (int j=0; j<nums1.size()-n; j++) {
                std::cout << "comparing nums1: " << nums1[j] << " with nums2: " << nums2[i] << std::endl;
                if (nums1[j] < nums2[i]) {
                    nums1.insert((nums1.begin()+j), nums2[i]);
                    break;
                }
            }
        }
        // clean the zeros
        for (int i=0; i<n; i++) {
            nums1.erase(nums1.begin() + m + n);
        }
    }
}


int main() {
    
    std::vector<int> vec1 {1,2,3,0,0,0};
    std::vector<int> vec2 {2,5,6};
    merge(vec1, 6, vec2, 3);
    std::cout << "vec1: ";
    for (auto& el : vec1) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
	return 0;
}
