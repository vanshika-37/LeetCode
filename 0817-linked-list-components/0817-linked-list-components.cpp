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
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* temp = head, *t = head;
        int i = 0, count = 0, n = 0;
        while(t){
            n++;
            t = t->next;
        }
        vector<int>v(n,-1);
        for (int i = 0; i < nums.size(); i++){
            v[nums[i]] = 1;
        }
        while(temp and temp->next){
            if (v[temp->val] == -1){
                temp = temp->next;
                continue;
            }
            if (v[temp->next->val] == -1){
                count++;
            }
            temp = temp->next;
        }
        if (v[temp->val] == 1){
            count++;
        }
        return count;
    }
};