/* A linked list is said to contain a cycle if any node is visited more than once while traversing the list. For example, in the following graph there is a cycle formed when node  points back to node .

image

Function Description

Complete the function has_cycle in the editor below. It must return a boolean true if the graph contains a cycle, or false.

has_cycle has the following parameter(s):

head: a pointer to a Node object that points to the head of a linked list.
Returns

boolean: True if there is a cycle, False if there is not
Note: If the list is empty,  will be null.

Input Format

There is no input for this challenge. A random linked list is generated at runtime and passed to your function.

Constraints

Sample Input

The following linked lists are passed as arguments to your function:

image

image

Sample Output

0
1
Explanation

The first list has no cycle, so we return false and the hidden code checker prints  to stdout.
The second list has a cycle, so we return true and the hidden code checker prints  to stdout. */
/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    
    if(head==NULL) return false;
    Node * slow = head;
    Node * fast = head->next;
    
    while(slow!=fast){
        if(fast==NULL || fast->next==NULL) return false;
        slow= slow->next;
        fast=fast->next->next;
    }
    return true;
}