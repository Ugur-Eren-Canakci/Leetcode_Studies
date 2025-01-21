// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

bool isBadVersion(int n) {
    return n >= 4;
}

int firstBadVersion(int n) {
    
    int l = 1, r = n;
    int m = l + (r-l)/2;
    
    while (l<=r) {
        if (isBadVersion(m)) {
            r = m-1;
            m = l + (r-l)/2;
        }
        else {
            l = m+1;
            m = l + (r - l)/2;
        }
        std::cout << "m is now " << m << std::endl;
        std::cout << "l: " << l << ", r: " << r << std::endl;
    } 
    return m;
}

int main() {
    
    std::cout << firstBadVersion(5);
    
    
    
    return 0;
}
