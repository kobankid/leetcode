/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *current, *prev, *result;
    int carry = 0;
    
    prev = current = NULL;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        current = malloc(sizeof(struct ListNode));
        if(prev == NULL) {
            result = current;
            prev = current;
        }

        int in1 = l1 ? l1->val : 0;
        int in2 = l2 ? l2->val : 0;
        int sum = in1 + in2 + carry; 
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        current->val = sum % 10; 
        carry = sum / 10;

        if(prev != current) {
            prev->next = current;
            prev = current;
        }
    }

    current->next = NULL;
    return result;
}

/*
1568 / 1568 test cases passed.
Status: Accepted
Runtime: 19 ms
Memory Usage: 7.7 MB
*/