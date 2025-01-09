/*
Delete N nodes after M nodes of a linked list
https://www.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1
*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* node=head;
        while(node!=NULL){
            int copym=m-1;
            while(node!=NULL && copym>0){
                node=node->next;
                copym--;
            }
             // If we've reached the end of the list, stop
            if (node == NULL) break;
            
            Node* curr=node->next;
            int deleten=n;
            while(curr && deleten--){
                Node* todel=curr;
                curr=curr->next;
                delete todel;
            }
            node->next=curr;
            node=node->next; // move to the current element
        }
        return head;
    }
};