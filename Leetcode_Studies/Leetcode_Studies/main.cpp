
// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode


/*Q1: Two Sum, 11ms
unordered_map<int,int> hash;
        for (int i=0; i<nums.size(); ++i){
            hash[nums[i]] = i; //record the values in a map so that you don't have to scour the whole list again
        }

        for (int i=0; i<nums.size(); ++i){
            int diff = target - nums[i];
            if (hash.find(diff) != hash.end() && hash[diff] != i) {
                return {i,hash[diff]};
            }
        }

        return {};
*/


/* Q2: Add Two Numbers, 27ms
 * // form a new ListNode
        ListNode* l = new ListNode((l1->val + l2->val)%10);
        bool carry = (l1->val + l2->val) > 9 ? true : false ;
        
        ListNode* first_it = l1;
        ListNode* second_it = l2;
        ListNode* return_it = l;
    
        while (first_it->next != nullptr && second_it->next != nullptr) 
        {
            first_it = first_it->next;
            second_it = second_it->next;
            
            return_it->next = new ListNode((first_it->val + second_it->val + (carry ? 1 : 0))%10); // formed the next digit
            carry = (first_it->val + second_it->val + (carry ? 1 : 0)) > 9 ? true : false;
            
            return_it = return_it->next;// iterated for the next loop
            
        };

        if (first_it->next == nullptr && second_it->next != nullptr) {
            while (second_it->next != nullptr) {
                second_it = second_it->next;
                
                return_it->next = new ListNode((second_it->val + (carry ? 1 : 0)) % 10); // formed the next digit
                carry = (second_it->val + (carry ? 1 : 0)) > 9 ? true : false;

                return_it = return_it->next;// iterated for the next loop 
            }
            if (carry) {
                return_it->next = new ListNode(1);
            }
            
        }
        else if (first_it->next != nullptr && second_it->next == nullptr) {
            while (first_it->next != nullptr) {
                first_it = first_it->next;

                return_it->next = new ListNode((first_it->val + (carry ? 1 : 0)) % 10); // formed the next digit
                carry = (first_it->val + (carry ? 1 : 0)) > 9 ? true : false;

                return_it = return_it->next;// iterated for the next loop 
            }
            if (carry) {
                return_it->next = new ListNode(1);
            }
        }
        else {
            if (carry) {
                return_it->next = new ListNode(1);
            }
        };

        return l;
*/

/* Q3: Longest Substring Without Repeating Characters, 1121 ms
 * const int& s_length = s.length();
        if (s_length == 0) {
            return 0;
        }

        std::set<char> unique_chars(s.begin(), s.end());
        const int& num_uniq = unique_chars.size();

        // non-repeating substrings cannot have length > num_uniq
        // if a substring has length > num_uniq, then it has to have a repeating char
        // pigeonhole principle

        int sub_str_length = num_uniq;
        while (sub_str_length > 1) {
            for (int i = 0; i < (s_length - sub_str_length + 1); i++) {

                std::string sub_str = s.substr(i, sub_str_length);

                std::set<char> sub_unique_chars(sub_str.begin(), sub_str.end());
                int sub_num_uniq = sub_unique_chars.size();

                if (sub_num_uniq == sub_str_length) { // if num of unique chars is equal to the currently checked length of substring,
                    return sub_str_length; // then we found the right substring
                }
            }
            --sub_str_length;
        }
        return 1;
 * 
 * 
 * 
 * */
/* Q9: Palindrome Numbers, 0ms
 * 
 * std::string temp = std::to_string(x);
        int val = 0;
        for (int i=0; i<temp.length(); i++) {
            if (temp[i] == temp[temp.length()-1-i]) val++;
            else return false; 
        }
        return true;
 * */
int main() {

	return 0;
}
