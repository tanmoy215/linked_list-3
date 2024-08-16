#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
  Node* deleteDuplicates(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        Node* fake = new Node(0);
        fake->next = head;
        Node* prev = fake;
        Node* curr = head;

        while (curr != NULL) {
            // Skip nodes with the same value
            while (curr->next != NULL && curr->data == curr->next->data) {
                curr = curr->next;
            }

            // If prev->next is still curr, no duplicates were found, move prev forward
            if (prev->next == curr) {
                prev = prev->next;
            } else {
                // Skip all duplicates
                prev->next = curr->next;
            }

            curr = curr->next;
        }

        return fake->next;
     }
int main(){
     Node* head = new Node(10);
   Node* a = new Node(50);
   Node* b = new Node(50);
   Node* c = new Node(60);
   Node* d = new Node(90);
   Node* tail = new Node(90);
   head->next = a;
   a->next = b;
   b->next = c;
   c->next = d;
   d->next = tail;
   display(head);
   head = deleteDuplicates(head);
   display(head);
    return 0;
}