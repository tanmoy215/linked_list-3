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
Node* addTwoNumbers(Node* l1, Node* l2) {
        int carry = 0;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        Node* a = l1;
        Node* b = l2;
        Node* c = new Node(0);
        Node* head = c;
        while (a or b) {
            int x = a ? a->data : 0;
            int y = b ? b->data : 0;
            int sum = x + y + carry;
            head->next = new Node(sum % 10);
            carry = sum / 10;
            head = head->next;
            if (a)
                a = a->next;
            if (b)
                b = b->next;
        }
        if (carry)
            head->next = new Node(carry);
          return c->next;
        }
void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    //list1
     Node* list1 = new Node(9);
   Node* a = new Node(5);
   Node* b = new Node(8);
   Node* c = new Node(6);
   Node* d = new Node(5);
   Node* tail = new Node(7);
   list1->next = a;
   a->next = b;
   b->next = c;
   c->next = d;
   d->next = tail;
   //list2
   Node* list2 = new Node(9);
   Node* a2 = new Node(5);
   Node* b2 = new Node(8);
   Node* c2 = new Node(6);
   Node* d2 = new Node(4);
   Node* tail2 = new Node(7);
   list2->next = a2;
   a2->next = b2;
   b2->next = c2;
   c2->next = d2;
   d2->next = tail2;
   cout<<"First List is : "<<endl;
   display(list1);
    cout<<"Second List is :  "<<endl;
   display(list2);
   list1 = addTwoNumbers(list1,list2);
   display(list1);
    return 0;
}