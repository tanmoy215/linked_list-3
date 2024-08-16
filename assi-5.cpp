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
int getDecimalValue(Node* head) {
          if(head==NULL) return 0;
          string str ="";
          Node* temp = head;
          while(temp){
            str+=(48+temp->data);
            temp=temp->next;
          }
          //convert decimal
          int result = 0;
          int n = str.length();
          for(int i=n-1;i>=0;i--){
            char ch = str[i];
            int nums = ch-'0';
            result+=nums*(1<<(n-i-1));
          }
          return result;
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
     Node* list1 = new Node(1);
   Node* a = new Node(0);
   Node* b = new Node(0);
   Node* c = new Node(1);
   Node* d = new Node(1);
   Node* tail = new Node(1);
   list1->next = a;
   a->next = b;
   b->next = c;
   c->next = d;
   d->next = tail;
   display(list1);
   int ans = getDecimalValue(list1);
   cout<<"Decimal value is : "<<ans<<endl;
    return 0;
}