
// Solutions are not meant to be executed here, as I don't have access to test cases
// All answers can be copy-pasted into the Solution member function definition in Leetcode

// Q1: Two Sum, 11ms
/*
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


// Q2: Add Two Numbers, 27ms
/*
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



int main() {

	return 0;
}
