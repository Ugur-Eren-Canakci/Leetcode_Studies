// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <array>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> next_permutation(vector<int>& nums) {
        // start iterating from end
        auto it = nums.rbegin()+1;
        
        // find an of decreasing value
        auto it_decrease = it;
        while (it != nums.rend()) {
            if (*it < *(it-1)) {
                it_decrease = it;
                break;
            }
            
        }

        // find the next smallest value on the right
        int min_val_on_right = *it_decrease;
        auto it_next = nums.rbegin();
        while (it_next < it_decrease) {
            if (*it_next > min_val_on_right) {
                min_val_on_right = *it_next;
                break;
            }
        }

        // swap values
        int temp = *it_next;
        *it_next = *it_decrease;
        *it_decrease = temp;
        std::cout << "after swap:";
        for (const auto& el : nums) std::cout << el << ",";
        std::cout << std::endl;

        // sort everything on the right
        sort(nums.rbegin(), it_decrease-1, [] (int x, int y) {return x > y;});

        return nums;
    }

size_t factorial(size_t n) {
        if (n < 2) return 1;
        return n*factorial(n-1);
    }

int main() {
    
    std::vector<int> nums{1,3,2};
    for (int i=0; i<factorial(nums.size()); i++) {
        nums = next_permutation(nums);
        std::cout << "after swap:";
        for (const auto& el : nums) std::cout << el << ",";
        std::cout << std::endl;
    }
    return 0;
}
