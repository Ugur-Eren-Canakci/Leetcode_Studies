// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

string addStrings(string num1, string num2) {
        if (num1=="0") return num2;
        if (num2=="0") return num1;
        
        // make num1 the larger/longer number
        int num1_value = 0, num2_value = 0;
        for (int i=0; i<num1.length(); i++) {
            num1_value += num1[i]*pow(10,num1.length()-1-i);
        }
        for (int i=0; i<num2.length(); i++) {
            num2_value += num2[i]*pow(10,num1.length()-1-i);
        }
        
        if (num1_value < num2_value) {
            string temp = num1;
            num1 = num2;
            num2 = temp;
        }
        
        num1 = "0" + num1;
        bool add_to_next = false;

        int num1_length = num1.length();
        int num2_length = num2.length();

        int it = 0;
        while (it < num2_length) {
            int digit_1 = int(num1[num1_length-1-it]-48);
            int digit_2 = int(num2[num2_length-1-it]-48);
            std::cout << "adding " << digit_1 << " and " << digit_2 << std::endl;
            if (add_to_next) {
                num1[num1_length-1-it] = char(((digit_1 + digit_2 + 1) % 10) + 48);
                if (digit_1 + digit_2 + 1 > 9) add_to_next = true;
            }
            else {
                num1[num1_length-1-it] = char(((digit_1 + digit_2) % 10) + 48);
                if (digit_1 + digit_2 > 9) add_to_next = true;
            }
            it++;
        }

        while (it < num1_length) {
            int digit_1 = int(num1[num1_length-1-it]-48);
            if (add_to_next) {
                num1[num1_length-1-it] = char(((digit_1 + 1) % 10) + 48);
                if (digit_1 + 1 > 9) add_to_next = true;
                else add_to_next = false;
            }
            else {
                num1[num1_length-1-it] = char((digit_1  % 10) + 48);
                if (digit_1 > 9) add_to_next = true;
                else add_to_next = false;
            }
            it++;
        }
        
        if (num1[0] == '0') {
            string res = "";
            for (int i=1; i<num1.size(); i++) res+=num1[i];
            return res;
        }
        return num1;

    }
    
    
int main() {
    
    std::cout << addStrings("408","5") << std::endl;
    
    
    return 0;
}
