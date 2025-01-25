// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

int longestPalindrome(string s) {
        if (s.length() < 2) return 1;
        
        int counts[52] = {0};
        for (char c : s) {
            if (int(c) > 64 && int(c) < 91) counts[c - 'A']++;
            else if (int(c) > 96 && int(c) < 123) counts[c - 'a' + 26]++;
        }

        int num_of_unique_chars = 0;
        for (int i=0; i<52; i++) {
            std::cout << counts[i] << ",";
            if (counts[i] > 0) num_of_unique_chars++;
        }
        std::cout << std::endl;
        
        if (num_of_unique_chars == 1) return s.length();

        int res = 0;
        int odd_count = 0;
        for (int i=0; i<52; i++) {
            if (counts[i] % 2 == 0) res += counts[i];
            else if (counts[i] % 2 == 1 && counts[i] > odd_count) {
                odd_count = counts[i];
            }
        }
        return res + odd_count ;
    }
    
    
int main() {
    
    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    std::cout << longestPalindrome(s) << std::endl;
    
    
    return 0;
}
