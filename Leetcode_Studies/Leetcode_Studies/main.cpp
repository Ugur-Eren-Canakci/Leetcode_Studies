// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <iostream>
#include <cmath>


std::uint32_t reverseBits(uint32_t n) {
        std::uint32_t original_number = n;
        std::vector<int> bits;
        while (original_number>0) {
            bits.push_back(original_number % 2);
            original_number /= 2;
        }

        std::uint32_t res = 0;
        for (const auto& el : bits) {
            res *= 2;
            res += el;
        }

        int length_1=0, length_2=0;
        std::uint32_t temp_1 = n, temp_2 = res;
        while (temp_1 > 0) {
            length_1++;
            temp_1 /= 2; 
        }
        while (temp_2 > 0) {
            length_2++;
            temp_2 /= 2; 
        }
        std::cout << "temp_1: " << temp_1 << ", temp_2: " << temp_2 << std::endl;
        for (int i=0; i<length_1 - length_2; i++) {
            res *= 2;
        }
        return res;
    }

int main() {
    
    std::cout << reverseBits(0b00000010100101000001111010011100);
    return 0;
}
