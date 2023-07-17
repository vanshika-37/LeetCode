/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* l){
        ListNode* prev = NULL, *curr = l, *nxt;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0;
        ListNode* h1 = l1, *h2 = l2;
        ListNode* h3 = new ListNode();
        ListNode* l3 = h3;
        while(h1 and h2){
            h3->val = (h1->val + h2->val + carry) % 10;
            carry = (h1->val + h2->val + carry) / 10;
            h3->next = new ListNode();
            h3 = h3->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        while(h1){
            h3->val = (h1->val + carry) % 10;
            carry = (h1->val + carry) / 10;
            h3->next = new ListNode();
            h3 = h3->next;
            h1 = h1->next;
        }
        while(h2){
            h3->val = (h2->val + carry) % 10;
            carry = (h2->val + carry) / 10;
            h3->next = new ListNode();
            h3 = h3->next;
            h2 = h2->next;
        }
        while(carry){
            h3->val = carry % 10;
            carry = carry / 10;
            h3->next = new ListNode();
            h3 = h3->next;
        }
        l3 = reverse(l3);
        if (l3->val == 0){
            l3 = l3->next;
        }
        return l3;
    }
};