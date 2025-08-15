#include <iostream>
using namespace std;

struct Node{
    Node *next;
    int data;
    Node(int x){
        next=NULL;
        data=x;
    }
};

void rprint(Node *head){
    if(head==NULL){
        return;
    }
    cout<<(head->data)<<" ";
    rprint(head->next);
}



Node *insertatbeginning(Node *head,int x){
    Node *temp=new Node(x); //MAKE NEW NODE TEMP AND THEN SLIDE THE HEAD TO 1 UNIT RIGHT
    temp->next=head;
    return temp;
}

Node *insertatend(Node *head,int x){
    Node *temp=new Node(x);
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

Node *insertatk(Node *head,int pos,int data){
    Node *temp=new Node(data);
    if(pos==1){
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    for(int i=1;i<=pos-2;i++){
        curr=curr->next;
    }
    if(curr==NULL){
        return head;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;

}


Node *deletefirstnode(Node *head){
    if(head==NULL){return NULL;}
    else{
        Node*temp=head->next;
        delete head;
        return temp;
    }
}

Node* deletelastnode(Node* head) {
    if (head == NULL) return NULL; 
    if (head->next == NULL) { 
        delete head;
        return NULL;
    }

    Node* curr = head;
    while (curr->next->next != NULL) { 
        curr = curr->next;
    }

    delete curr->next; 
    curr->next = NULL; 
    return head;
}

int rsearch(Node* head,int x){
    if(head==NULL){return -1;}
    if(head->data==x){return 1;}
    else{
        int res=rsearch(head->next,x);
        if(res==-1){return -1;}
        else return (res+1);
    }
}
int search(Node* head,int x){
    int pos=1;
    Node *curr=head;
    while(curr!=NULL){
        if(curr->data==x){
            return pos;
        }
        else{
            pos++;
            curr=curr->next;
        }
    }return -1;
}
int main(){
    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    head->next->next=temp2;
    // head=insertatbeginning(head,2);
    // head=insertatbeginning(head,534);
    // head=insertatbeginning(head,243);
    // head=insertatend(head,345);
    // head=insertatk(head,2,29);
    // head=deletelastnode(head);
    cout<<search(head,30);
    // rprint(head);
    return 0;
}
//TC=O(N)