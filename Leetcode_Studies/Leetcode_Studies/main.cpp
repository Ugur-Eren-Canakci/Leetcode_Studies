// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

int addDigits(int num) {
        
    if (num == 0) return 0;
    vector<int> digits;

    while (num > 0) {
        std::cout << "digit to add: " << num % 10 << std::endl;
        digits.push_back(num % 10);
        num = num/10;
        std::cout << "now num is " << num << std::endl;
    }
    
    if (digits.size() == 1) return digits[0];
    int temp = 0;
    for (const auto& el : digits) {
        temp += el;
    }

    return addDigits(temp);
}

int main() {
    
    addDigits(2);
    
    
    
    return 0;
}
