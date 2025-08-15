#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};



void rprint(Node *head){
    if(head==NULL){
        return;
    }
    cout<<(head->data)<<" ";
    rprint(head->next);
}

int main(){
    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    head->next->next=temp2;
    rprint(head);
    return 0;
}
