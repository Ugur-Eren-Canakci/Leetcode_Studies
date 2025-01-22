// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

void moveZeroes(vector<int>& nums) {
    if (nums.size() < 2) {}
    else {
        int zeros = 0;
        for (const auto& el : nums) {
            if (el == 0) zeros++;
        }
        
        auto it = nums.begin();
        while (zeros > 0 && it != nums.end()) {
            std::cout << "num of zeros: " << zeros;
            if (*it == 0) {
                nums.erase(it);
                zeros--;
                it = nums.begin();
            }
            else it++;
        }
    }
}

int main() {
    
    vector<int> nums{0,1,0,3,12};
    
    moveZeroes(nums);
    
    
    return 0;
}
