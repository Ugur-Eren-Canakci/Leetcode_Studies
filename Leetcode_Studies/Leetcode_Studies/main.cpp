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

int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1 && dividend > 0) return -1*dividend;
        if (divisor == -1 && dividend < 0) {
            if (dividend == -1*pow(2,31)) return pow(2,31)-1;
            else return -1*dividend;
        }

        int quotient = 0;
        long new_dividend = dividend;
        if (new_dividend > 0 && divisor > 0 ) {
            while (new_dividend - divisor >= 0) {
            new_dividend -= divisor;
            quotient += 1;
            }
        }
        else if (new_dividend > 0 && divisor < 0) {
            while (new_dividend + divisor >= 0) {
                new_dividend += divisor;
                quotient -= 1;
            }
        }
        else if (new_dividend < 0 && divisor > 0) {
            while (new_dividend + divisor <= 0) {
                new_dividend += divisor;
                quotient -= 1;
            }
        }
        else {
            while (new_dividend - divisor <= 0) {
                new_dividend -= divisor;
                quotient += 1;
            }
        }

        return quotient;
    }

int main() {
    
    std::cout << 2147483647 << std::endl;
    std::cout << divide(-2147483648,-2147483648) << std::endl;
    
    return 0;
}
