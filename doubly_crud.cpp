#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
Node(int x){
    data=x;
    prev=NULL;
    next=NULL;
}};

Node *insertatbeginning(Node *head,int x){
    Node *temp=new Node(x);
    temp->next=head;
    if(head!=NULL){
        head->prev=temp;
    }return temp;
}

Node *insertatend(Node *head,int x){
     Node *temp=new Node(x);
     if(head==NULL){
        return temp;
     }
     Node *curr=head;
     while(curr->next!=NULL){
        curr=curr->next;
     }
     curr->next=temp;
     temp->prev=curr;
     return head;
}















int main(){
    Node *head= new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;

}