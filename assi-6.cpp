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
Node* reverse(Node* head){
  Node *curr = head,*prev = NULL,*Next = NULL;
    // Node* curr = head;
    // Node* prev = NULL;
    // Node* Next = NULL;
    while(curr!=NULL){
        Next = curr->next;
        curr->next = prev;
        prev=curr;
        curr = Next;
    }
    return prev;
}
int pairmax(Node* head){
    Node* fast = head;
        Node* mid = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            mid=mid->next;
        }
        Node* g = mid->next;
        mid->next = NULL;
        Node* sp = reverse(g);
        mid->next = sp;
        mid = mid->next;
        int m = INT_MIN;
        fast = head;
        while(mid!=NULL){
            int data = mid->data + fast->data;
            m = max(m,data);
            mid=mid->next;
            fast=fast->next;
        }
        return m;
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
   int ans = pairmax(head);
   cout<<"Max pair is : "<<ans<<endl;
    return 0;
}