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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // first insert the dummy node at the start of the ll 
        ListNode* dummy_head = new ListNode (69);
        dummy_head->next = head;

        ListNode* slow = dummy_head;
        ListNode* fast = dummy_head;

        while(n >= 0){
            fast = fast->next;
            n--;
        }

        while(fast != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }

        ListNode* temp = slow -> next;
        slow->next = slow->next->next;
        delete temp;

        return dummy_head->next;
    }
};
