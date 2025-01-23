// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> uniques_1, uniques_2;

        for (const auto& el : nums1) {
            uniques_1.insert(el);
        }

        for (const auto& el : nums2) {
            uniques_2.insert(el);
        }

        set<int> common_uniques;
        for (const auto& el : uniques_1) common_uniques.insert(el);
        for (const auto& el : uniques_2) common_uniques.insert(el);

        for (const auto& el : common_uniques) {
            std::cout << "common element: " << el << std::endl;
            int count_1=0, count_2=0;
            for (const auto& el_ : nums1) {
                if (el_ == el) count_1++;
            }
            for (const auto& el_ : nums2) {
                if (el_ == el) count_2++;
            }

            if (count_1 > 0 && count_2 > 0) res.push_back(min(count_1,count_2));
            else 
        }
        return res;
    }
    
    
int main() {
    
    vector<int> nums1{1,2,2,1};
    vector<int> nums2{2,2};
    for (const auto& el : intersect(nums1,nums2)) std::cout << el << " ";
    
    return 0;
}
