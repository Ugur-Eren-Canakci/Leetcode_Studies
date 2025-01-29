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

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        
        vector<vector<int>> res;
        set<vector<int>> uniques;
        
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size()-3; i++) {
            for (int j=i+1; j<nums.size() - 2; j++) {
                int left = j+1, right = nums.size() - 1;
                while (left < right ) {
                    int last_left = nums[left], last_right = nums[right];
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        uniques.insert(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        int last_left = nums[left], last_right = nums[right];
                        while (left < right && nums[left] == last_left) left++;
                        while (left < right && nums[right] == last_right) right--;
                    
                    } 
                    else if (sum < target) left++;
                    else right--;
                }
            }
        }
        
        for (const auto& el : uniques) res.push_back(el);
        return res;
    }

int main() {
    
    vector<int> vec{1,-2,-5,-4,-3,3,3,5};
    std::cout << vec.size() << std::endl;
    for (const auto& vector : fourSum(vec,-11)) {
        cout << "vector: [";
        for (const auto& el : vector) cout << el << ",";
        cout << "]" << endl;
    }
    
    return 0;
}
