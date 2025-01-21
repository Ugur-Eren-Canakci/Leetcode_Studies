// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return vector<string>{""};
        vector<string> big_vec;
        vector<int> vec{nums[0]};
        string str = "";
        for (int i=1; i<nums.size(); i++) {
            if (vec.empty()) vec.push_back(nums[i]);
            else if (vec.back() + 1 == nums[i]) vec.push_back(nums[i]);
            else {
                if (vec.size() != 1) {
                    str += to_string(vec.front());
                    str += "->";
                    str += to_string(vec.back());    
                }
                else str += to_string(vec.front());
                big_vec.push_back(str);
                str = "";
                vec = vector<int>{nums[i]};
            } 
        }
        if (!vec.empty()) {
            if (vec.size() != 1) {
                str += to_string(vec.front());
                str += "->";
                str += to_string(vec.back());    
            }
            else str += to_string(vec.front());
            big_vec.push_back(str);
        }

        return big_vec;
    }

int main() {
    vector<int> vec{0,1,2,4,5,7};
    auto res = summaryRanges(vec);
    for (const auto& el : res) cout << el << ",";
    
    return 0;
}
