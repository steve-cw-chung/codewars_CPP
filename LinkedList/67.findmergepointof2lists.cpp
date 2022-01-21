/* Given pointers to the head nodes of  linked lists that merge together at some point, find the node where the two lists merge. The merge point is where both lists point to the same node, i.e. they reference the same memory location. It is guaranteed that the two head nodes will be different, and neither will be NULL. If the lists share a common node, return that node's  value.

Note: After the merge point, both lists will share the same node pointers.

Example

In the diagram below, the two lists converge at Node x:

[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q
Function Description

Complete the findMergeNode function in the editor below.

findMergeNode has the following parameters:

SinglyLinkedListNode pointer head1: a reference to the head of the first list
SinglyLinkedListNode pointer head2: a reference to the head of the second list
Returns

int: the  value of the node where the lists merge
Input Format

Do not read any input from stdin/console.

The first line contains an integer , the number of test cases.

Each of the test cases is in the following format:
The first line contains an integer, , the node number where the merge will occur.
The next line contains an integer,  that is the number of nodes in the first list.
Each of the following  lines contains a  value for a node. The next line contains an integer,  that is the number of nodes in the second list.
Each of the following  lines contains a  value for a node.

Constraints

The lists will merge.
.
 .

Sample Input

The diagrams below are graphical representations of the lists that input nodes  and  are connected to.

Test Case 0

 1
  \
   2--->3--->NULL
  /
 1
Test Case 1

1--->2
      \
       3--->Null
      /
     1
Sample Output

2
3
Explanation

Test Case 0: As demonstrated in the diagram above, the merge node's data field contains the integer .
Test Case 1: As demonstrated in the diagram above, the merge node's data field contains the integer . */

#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    map<SinglyLinkedListNode*,int> m;
    SinglyLinkedListNode * pointer = head1;
    while(pointer!=NULL){
        if(m[pointer]==0){
            m[pointer]= 1;
        } else {
            m[pointer]++;
        }
        pointer= pointer->next;
    }
    pointer = head2;
    while(pointer!=NULL){
        if(m[pointer]==0){
            m[pointer]= 1;
        } else {
            m[pointer]++;
            return pointer->data;
        }
        pointer= pointer->next;
    }
    for (auto x : m){
        if(x.second==2){
            return x.first->data;
        }
    }
    return 0;
/*     SinglyLinkedListNode* p1 = head1->next;
    SinglyLinkedListNode* p2 = head2->next;
    while(p1!=p2){
        if(p2->next==NULL){
            p2=head2->next;
            p1=p1->next;
        }
    }
    return p2->data; */
}

int main()