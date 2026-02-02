#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *result = new ListNode(0, nullptr);
    ListNode *ptr_res = result;
    int carry = 0, sum;
    int start = true; 
    while (true) { 
      if (l1 == NULL || l2 == NULL) break;

      // Calculate the sum of the digit + the carry
      sum = l1->val + l2->val + carry;

      // If the sum of the digits are greater than 10, then carry = 1;
      if (sum >= 10) { 
        carry = 1; 
        sum = sum % 10; 
      } else carry = 0; 
      std::cout << "sum = " << sum << " | carry = " << carry << "\n";

      // Create a new node for the digit sum
      ListNode *sum_node = new ListNode(sum, nullptr);
      ptr_res->next = sum_node; 
      ptr_res = ptr_res->next;

      // Repeat the process until we reach the end of one of the lists;
      l1 = l1->next; 
      l2 = l2->next;  
    }
    // Adding the rest of the lists using the same method
    while (l1 != NULL) { 
      int sum = l1->val + carry;
      if (sum >= 10) { carry = 1; sum = sum % 10; }
      else carry = 0;
      ListNode* sum_node = new ListNode(sum, nullptr); 
      ptr_res->next = sum_node; 
      ptr_res = ptr_res->next; 
      l1 = l1->next; 
    }
    while (l2 != NULL) { 
      int sum = l2->val + carry;
      if (sum >= 10) { carry = 1; sum = sum % 10; }
      else carry = 0;
      ListNode* sum_node = new ListNode(sum, nullptr);
      ptr_res->next = sum_node; 
      ptr_res = ptr_res->next; 
      l2 = l2->next;
    }      
    // If there is an extra carry then we append it at the end 
    if (carry) { 
      ListNode* sum_node = new ListNode(carry, nullptr);
      ptr_res->next = sum_node; 
    }

    // Chopping off the extra 0 at the beginning of the list
    return result->next;
  }   
};