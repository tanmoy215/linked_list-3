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
Node* insertionSortList(Node* head) {
    Node *dummy = new Node(0);
    Node *temp = dummy;
    Node *curr = head , *nex = NULL;
        while(curr){
            nex = curr->next;
            temp = dummy;
                while(temp->next and temp->next->data < curr->data)
                        temp = temp->next;
                        curr->next = temp->next;
                        temp->next = curr;
                        curr = nex;
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
     Node* head = new Node(90);
   Node* a = new Node(50);
   Node* b = new Node(80);
   Node* c = new Node(60);
   Node* d = new Node(450);
   Node* tail = new Node(70);
   head->next = a;
   a->next = b;
   b->next = c;
   c->next = d;
   d->next = tail;
   display(head);
   head = insertionSortList(head);
   display(head);
    return 0;
}