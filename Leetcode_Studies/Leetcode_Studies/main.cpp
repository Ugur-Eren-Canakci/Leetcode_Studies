// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

int myAtoi(string s) {
        if (s.length() == 0) return 0;

        // remove leading whitespaces
        string temp{""};
        int non_whitespace = -1;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == ' ') continue;
            else {
                non_whitespace = i;
                break;
            }
        }
        
        for (int i=non_whitespace; i<s.length(); i++) temp += s[i];
        if (temp.size() < 1) return 0;
        std::cout << "after whitespace removal, temp is " << temp << std::endl;

        // check sign
        bool is_negative = false;
        if (temp[0] == '-' || temp[0] == '+') {
            if (temp[0] == '-') is_negative = true;
            string new_temp{""};
            for (int i=1; i<temp.size(); i++) new_temp += temp[i];
            temp = new_temp;
        }
        if (temp.size() < 1) return 0;
        std::cout << "after sign removal, temp is " << temp << std::endl;
        
        // conversion step
        // 0000000000012345678
        // 21474836460 -> last zero shouldn't go away
        string new_temp{""};
        int nonzero_index = -1;
        for (int i=0; i<temp.size(); i++) {
            if (isdigit(temp[i])) {
                if (temp[i] == '0' && nonzero_index == -1) continue;
                else if (temp[i] == '0' && nonzero_index >= 0) new_temp += temp[i];
                else if (temp[i] != '0' && nonzero_index == -1) {
                    nonzero_index = i;
                    new_temp += temp[i];
                }
                else new_temp += temp[i];
            }
            else break;
        }
        temp = new_temp;
        if (temp.size() < 1) return 0;
        std::cout << "after conversion, temp is " << temp << std::endl;

        // finally calculate the value
        // 20000000000000000000
        if (temp.size() > 10) {
            if (is_negative) return (-1)*pow(2,31);
            else return pow(2,31)-1;
        }
        else {
            long long val = 0;
            for (int i=0; i<temp.size(); i++) {
                if ((temp[i] - '0')*pow(10,temp.size()-1-i) > pow(2,31) && is_negative) return (-1)*pow(2,31);
                else if ((temp[i] - '0')*pow(10,temp.size()-1-i) > pow(2,31) && !is_negative) return pow(2,31) - 1;
                else val += (temp[i] - '0')*pow(10,temp.size()-1-i);
            }

            std::cout << "val is " << val << std::endl;
            if (is_negative) {
                std::cout << "negative flag" << std::endl;
                return int((-1)*val);
            }
            else return int(val);
        }
    }

int main() {
    
    string s = "2147483648";
    std::cout << myAtoi(s) << std::endl;

    return 0;
}
