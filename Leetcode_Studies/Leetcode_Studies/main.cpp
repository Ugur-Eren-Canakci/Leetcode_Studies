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

class Solution {
public:
    static vector<int> factorials; 
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
            it++;
        }
        // if it is nums.rend(), then the vector is in decreasing order
        if (it == nums.rend()) {
            sort(nums.begin(),nums.end());
            return nums;
        }
        // find the next smallest value on the right
        int min_val_on_right = *it_decrease;
        auto it_next = nums.rbegin();
        while (it_next < it_decrease) {
            if (*it_next > min_val_on_right) {
                min_val_on_right = *it_next;
                break;
            }
            it_next++;
        }
        // swap values
        int temp = *it_next;
        *it_next = *it_decrease;
        *it_decrease = temp;
        // sort everything on the right
        sort(nums.rbegin(), it_decrease, [] (int x, int y) {return x > y;});
        return nums;
    }

    int factorial(int n) {
        if (factorials.size() > n) return factorials[n];
        else {
            for (int i=factorials.size()-1; i<n; i++) {
                factorials[i] = i*factorials[i-1];
            }
        } 

        return factorials[n];
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> unique_permutations{nums};

        for (int i=1; i<factorial(nums.size()); i++) {
            vector<int> next = next_permutation(nums);
            nums.swap(next);
            unique_permutations.insert(nums);
        }

        vector<vector<int>> res;
        for (const auto& el : unique_permutations) res.push_back(el);

        return res;
    }
};

vector<int> Solution::factorials{1,1};

int main() {
    
    Solution s;
    
    std::cout << s.factorial(0) << std::endl;
    std::cout << s.factorial(1) << std::endl;
    std::cout << s.factorial(2) << std::endl;
    std::cout << s.factorial(3) << std::endl;
    std::cout << s.factorial(4) << std::endl;
    return 0;
}
