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

vector<int> searchRange(vector<int>& nums, int target) {
        
        if (nums.empty()) return {-1,-1};
        if (nums.size() == 1) {
            if (nums[0] == target) return {0,0};
            else return {-1,-1};
        }
        if (nums.size() == 2) {
            if (nums[0] == target && nums[1] == target) return {0,1};
            else if (nums[0] == target && nums[1] != target) return {0,0};
            else if (nums[0] != target && nums[1] == target) return {1,1};
            else return {-1,-1};
        }
        if (nums[0] == target && nums[1] > target) return {0,0};
        if (nums[nums.size()-1] == target && nums[nums.size()-2] < target) return {int(nums.size()-1),int(nums.size()-1)};
        int left = 0, right = nums.size() - 1;
        int mid = (left + right)/2;
        while (left <= right) {
            mid = (left + right)/2;
            if (target == nums[mid]) break;
            if (target < nums[mid]) right = mid - 1;
            else if (target > nums[mid]) left = mid + 1;
        }

        if (nums[mid] == target) {
            int left_pos = mid, right_pos = mid;
            if (left_pos > 0) {
                while (nums[left_pos-1] == target && left_pos > 0) left_pos--;
            }
            if (right_pos < nums.size()-2) {
                while (nums[right_pos+1] == target && right_pos < nums.size()-2) right_pos++;
            }
            return {left_pos,right_pos};
        }

        return {-1,-1};
    }

int main() {
    
    vector<int> vec {1,1,2};
    vector<int> res = searchRange(vec,1); 
    
    for (int i=0; i<2; i++) {
        std::cout << res[i] << ",";
    }
    std::cout << std::endl;
    return 0;
}
