

/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if (!l1  && !l2 ) return NULL;
        ListNode * temp = new ListNode(0);
        ListNode * ptr = temp;
        int carry = 0;
        while ( l1 != NULL  ||  l2 != NULL ) {
           if (l1 == NULL ) {
              ptr->next = new ListNode ( (l2->val + carry ) % 10 );
              carry = (l2->val + carry) / 10;
              l2 = l2->next;
           } else if ( l2 == NULL ) {
              ptr->next = new ListNode ( (l1->val + carry ) % 10 );
              carry = (l1->val + carry) / 10;
              l1 = l1->next;
           } else {
              ptr->next = new ListNode ( (l2->val + l1->val  + carry ) % 10 );
              carry = (l2->val + l1->val  + carry) / 10;
              l2 = l2->next;
              l1 = l1->next;
           }
            
            ptr = ptr->next;
        }
        if (carry == 1 )  ptr->next = new ListNode (1);
        return temp->next;
    }
