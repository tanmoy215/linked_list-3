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
Node* Oddeven(Node* head) {
  if(head==NULL || head->next == NULL) return head;
          Node* temp = head;
          Node* a = new Node(-1);
          Node* b = new Node(-1);
          Node* ta = a;
          Node* tb = b;
          int n=1;
          while(temp){  //temp means temp->next!=NULl
                if(n%2!=0){  //Odd Index
                     ta->next = temp;
                     temp = temp->next;
                     ta=ta->next;
                }
                else{  //Even Index
                    tb->next = temp;
                    tb=tb->next;
                    temp = temp->next;
                }
                n++;
          }
         if(b) tb->next = NULL;
         if(b) ta->next = NULL;
          a=a->next;
          b=b->next;
          temp = a;
          while(temp->next!=NULL){
            temp = temp->next;
          }
          temp->next = b;
          return head;
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
   head = Oddeven(head);
   display(head);
    return 0;
}