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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail=head;
        int len =1;
        if (head == nullptr || head->next == nullptr)
        return head;
        while(tail->next){
            len++;
            tail = tail->next;
        }
        if(k%len==0) return head;
        k=k%len;
        tail->next=head;
        for(int i =0;i<len-k-1;i++){
            head=head->next;
        }
        ListNode* newtail=head;
        ListNode* newhead = newtail->next;
        newtail->next =nullptr;
        return newhead;
    }
};