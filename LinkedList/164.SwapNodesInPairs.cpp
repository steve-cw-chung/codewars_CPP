/* Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100 */
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
    ListNode* swapPairs(ListNode* head) {
        if(!head){
		    return head;
        }
        if(!head->next){
            return head;
        }
        ListNode*prevprev;
        ListNode*prev = head;
        ListNode*curr=head->next;
        head = curr;
        while(curr){
            prev->next = curr->next;
            curr->next = prev;
            
            if(prev->next&&prev->next->next){
                prevprev= prev;
                prev=prev->next;
                curr=prev->next;
                prevprev->next= curr;
              
                
            }else{
                break;
            }
            
        }
        return head;
    }
};