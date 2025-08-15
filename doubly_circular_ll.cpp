#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};

Node* insertathead(Node *head,int x){
    Node* temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        temp->prev=temp;
    }
    temp->prev=head->prev;
    temp->next=head;
    head->prev->next=temp;
    head->prev=temp;
    return temp;
}

Node *sortedinsert(Node* head,int x){
    Node* temp=new Node(x);
    if(head==NULL){
        return temp;
    }
    if(x<head->data){
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    while(curr->next!=NULL &&curr->next->data)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

int main(){
    Node* head=new Node(10);
    Node* temp1=new Node(20);
    Node* temp2=new Node(30);
    
}