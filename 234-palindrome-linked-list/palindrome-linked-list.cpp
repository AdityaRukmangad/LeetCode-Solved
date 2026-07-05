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
    ListNode* reverse(ListNode* head){
        if(head == nullptr || head->next == nullptr)
        return head;
        ListNode* newhead = reverse(head->next);
        ListNode* front = head -> next;
        front -> next =head;
        head ->next =NULL;
        return newhead; 
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow =head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow =slow->next;
            fast = fast ->next ->next;
        }
        ListNode* second =reverse(slow);
        ListNode* first =head;
        while(second!=nullptr){
            if(first->val!=second->val)
            return false;
        
        first= first->next;
        second=second->next;
        }
        return true;
    }
};