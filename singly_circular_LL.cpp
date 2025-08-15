#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printList(Node *head){
    if(head==NULL) return;
    Node *p=head;
    do{
        cout<<(p->data)<<" ";
        p=p->next;
    }while(p!=head);

}
// NAIVE SOLN
// Node* insertatbegin(Node* head, int x) {
//     Node* temp = new Node(x);
//     if (head == NULL) {
//         temp->next = temp; 
//         return temp;
//     }

//     Node* curr = head;
//     while (curr->next != head) {
//         curr = curr->next;
//     }

//     curr->next = temp; 
//     temp->next = head;  
//     return temp;        
// }
Node *insertbegin(Node*head,int x){
    Node *temp=new Node(x);
    if(head==NULL) {temp->next=temp;return temp;}
    else{
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return head;

    }
}
// NAIVE SOLN
// Node* insertend(Node* head, int x) {
//     Node* temp = new Node(x);

//     if (head == NULL) { 
//         temp->next = temp; 
//         return temp;
//     }

//     Node* curr = head;
//     while (curr->next != head) { 
//         curr = curr->next;
//     }

//     curr->next = temp; 
//     temp->next = head; 
//     return head;      
// }

Node* insertend(Node *head,int x){
    Node* temp=new Node(x);
    if(head==NULL){
        
            temp->next=temp;
            return temp;
        
    }
    else{
        temp->next=head->next;
        head->next=temp;
        int t=temp->data;
        temp->data=head->data;
        head->data=t;
        return temp; 
    
    } 
}

Node* delhead(Node *head){
    if(head==NULL) return NULL;
    if(head->next==head){
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    Node * temp=head->next;
    head->next=head->next->next;
    delete temp;
    return head;
}

Node* delkth(Node *head,int k){
    if(head==NULL) return head;
    if(k==1) return delhead(head);
    Node *curr=head;
    for(int i=0;i<k-2;i++){
        curr=curr->next;
    }
    Node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}



int main(){
    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    head->next->next=temp2;
    head->next->next->next=head;
    head=delkth(head,3);
    // head=insertend(head,50);
    printList(head);
    return 0;
}