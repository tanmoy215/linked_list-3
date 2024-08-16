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
int length(Node* head) {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }
    Node* reverseKGroup(Node* head, int k) {
        int len = length(head);
        if (!head or len < k)
            return head;
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* curr = dummy;
        Node* prev = dummy;
        Node* nex = dummy;
        while (len >= k) {
            curr = prev->next;
            nex = curr->next;
            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            len -= k;
        }
        return dummy->next;
    }
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
     Node* head = new Node(7);
   Node* a = new Node(5);
   Node* b = new Node(8);
   Node* c = new Node(6);
   Node* d = new Node(4);
   Node* tail = new Node(3);
   head->next = a;
   a->next = b;
   b->next = c;
   c->next = d;
   d->next = tail;
   display(head);
   int k  = 2;
   head = reverseKGroup(head,k);
   display(head);
    return 0;
}