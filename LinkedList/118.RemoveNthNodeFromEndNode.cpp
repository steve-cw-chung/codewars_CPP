/* Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz */
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
        //fast goes first slow goes n behind?
        //case 1 : n is last element
        ListNode * fast = head;
        int counter = 0;

        while (counter<n){
            cout << counter <<endl;
            if(fast->next){
                fast=fast->next;
            }else{
                
                if(n==1){
                    return nullptr;
                }else{
                    return head->next;
                }
                
            }
            counter++;
        }
        ListNode* slow = head;

        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        fast = slow->next;
        slow->next = fast->next;
        //delete(fast);
        return head;
    }
};