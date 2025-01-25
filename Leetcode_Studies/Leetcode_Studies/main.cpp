// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

string toHex(int num) {
        string res = "";
        
        if (num < 0) {
            // convert to base 2 string
            int arr[32] = {0};
            int power = 0;
            int temp = -num;
            // invert the digits
            while (power < 32) {
                arr[31 - power] = 1 - temp%2;
                temp /= 2;
                power++;
            }
            arr[0] = 0;
            // add 1
            int counter = 31;
            bool addToNextDigit = true;
                
            while (addToNextDigit) {
                if (arr[counter] == 1) {
                    arr[counter] = 0;
                    addToNextDigit = true;
                }
                else {
                    arr[counter] = 1;
                    addToNextDigit = false;
                } 
                counter--;
            }
            
            
            for (int i=0; i<32; i++) std::cout << arr[i];
            std::cout << std::endl;
            // now arr is the binary rep. of num that's inversed w.r. to the "two's complement" method
            
            // each group of 4-slots will turn into one digit in the hexadecimal representation
            // for example, slots 0 to 3 is the most significant digit
            // slots 4 to 7 is the next most significant digit, and so on
            int group = 0;
            while (group < 8) {
                // get the digit value of the current group
                int current_val = 0;
                if (group == 0) current_val = 8;
                for (int i=0; i<4; i++) {
                    current_val += arr[4*group + i]*pow(2,3-i);
                }
                if (current_val > 9) {
                    char temp = 'a' - 10 + current_val;
                    res += temp;
                }
                else res += to_string(current_val);
                std::cout << "now the returned string is " << res << std::endl;
                group++;
            }
            return res;
        }
        
        while (num != 0) {
            if (num % 16 > 9) {
                char temp = 'a' - 10 + (num%16);
                res = temp + res;
            }
            else res = to_string(num%16) + res;
            num /= 16; 
        }

        return res;
    }
    
    
int main() {
    
    std::cout << toHex(-1) << std::endl;
    std::cout << toHex(-2) << std::endl;
    std::cout << toHex(-3) << std::endl;
    
    return 0;
}
