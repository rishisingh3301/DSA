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
//at tail
//at position
//before given value

//deletion
//at head
Node* deletehead(Node* head){
    //if there is already no head at all
    if(head==NULL){return head;}
    Node* temp=head;
    temp=head->next;
    delete head;
    return temp;
}
//at tail
Node* deletetail(Node* head){
    //if there is no head or just one element present then after tail deletion LL will be null
    if(head==NULL || head->next==NULL){return NULL;}
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
//at position
Node *delatpos(Node* head,int k){
    if(head==NULL){return head;}
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int c=0;
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        c++;
        if(c==k){
            prev->next=prev->next->next;
            delete temp;
            return head;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;    
}
//of given value
Node* delvalue(Node* head, int val){
    if(head==NULL)return head;
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==val){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
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
    vector<int> arr={5,10,15,20};
    Node* head=convertarraytoLL(arr);
    print(head);
    //delete
    //head
    // head=deletehead(head);
    // print(head);
    //tail
    // head=deletetail(head);
    // print(head);
    //at pos
    // head=delatpos(head,5);
    // print(head);
    //given value
    // head=delvalue(head,20);
    // print(head);

    
    return 0;
}