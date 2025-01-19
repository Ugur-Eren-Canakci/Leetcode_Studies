// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

bool isHappy(int n) {
        static std::set<int> squares;
        for (const auto& el : squares) std::cout << el << ", ";
        std::cout << std::endl;
        
        std::vector<int> digits;
        while (n>0) {
            digits.push_back(n%10);
            n /= 10;
        }
        int square_of_digits = 0;
        for (const auto& el : digits) square_of_digits += el*el;
        
        
        if (square_of_digits == 1) return true;
        else if (squares.insert(square_of_digits).second) return isHappy(square_of_digits);
        else return false;
    }

int main() {
    
    std::cout << std::boolalpha;
    std::cout << isHappy(13) << isHappy(10);
    return 0;
}
