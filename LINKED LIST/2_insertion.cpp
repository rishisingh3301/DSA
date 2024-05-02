#include <bits/stdc++.h>
using namespace std;
//Linkedlist creator node
struct Node{
    public:
    int data;
    Node* next;

    //Constructor
    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
//convert array to Linked list
Node* convertarraytoLL(vector<int>&arr){
    // if(arr[0]==NULL){return new Node(NULL,nullptr);}
    Node* head=new Node(arr[0]);
    Node* mover=head;//mover which go throughout array
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        // mover=temp;//this also works
        mover=mover->next;
    }
    return head;
}
//Linkedlist print
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//insertion
//at head
Node* inserthead(Node* head, int val){
    if(head==NULL){
        Node* newhead=new Node(val);
        return newhead;}
    Node* temp= new Node(val,head);
    return temp;
}
//at tail
Node* insertattail(Node* head, int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    Node* newval=new Node(val);
    temp->next=newval;
    return head;
}
//at position
Node* insertatpos(Node* head, int pos, int val){
    if(head==NULL){if(pos==1)return new Node(val);}
    if(pos==1){
        Node* temp=new Node(val,head);
        return temp;
    }
    int c=0;
    Node* temp=head;
    while(temp!=NULL){
        c++;
        if(c==pos-1){
            Node* newval=new Node(val,temp->next);
            temp->next=newval;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//before given value
Node* insertbeforevalue(Node* head,int beforeval,int val){
     if(head==NULL){return NULL;}
    if(head->data==beforeval){
        Node* temp=new Node(val,head);
        return temp;
    }
    
    Node* temp=head;
    while(temp!=NULL){
        if(temp->next->data==beforeval){
            Node* newval=new Node(val,temp->next);
            temp->next=newval;
            break;
        }
        temp=temp->next;
    }
    return head;
    
}

int main(){
    //creating a node
    // Node* x=new Node(5);
    // Node* y=new Node(6);
    // x->next=y;
    // cout<<x<<" "<<x->data<<" "<<x->next<<" "<<y<<" "<<y->data<<" "<<&(x->next)<<" "<<&y;

    //convertarraytoLL
    vector<int> arr={1,3,5,7,9};
    Node* head=convertarraytoLL(arr);
    print(head);

    //insert at head
    // head=inserthead(head,6);
    // print(head);

    //insert at tail
    // head=insertattail(head,7);
    // print(head);

    //insert at position
    // head=insertatpos(head,1,600);
    // print(head);

    //insert before value
    head=insertbeforevalue(head,0,100);
    print(head);
    return 0;
}