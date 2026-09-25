/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //insert copies in middle
        Node * curr = head;
        Node * next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = new Node(curr->val);
            curr=curr->next;
            curr->next= next;
            curr=curr->next;
        }

        //connect the nodes to corresponding random
        curr = head;
        while(curr!=NULL){
            curr->next->random = (curr->random!=NULL)?(curr->random->next):NULL;
            curr=curr->next->next;
        }
        //reset the original and present
        curr=head;
        Node * temp = new Node(-1);
        Node * curr2 = temp;
        while(curr!=NULL){
            curr2->next=curr->next;
            curr->next=curr->next->next;
            curr=curr->next;
            curr2=curr2->next;
        }
        return temp->next;

    }
};