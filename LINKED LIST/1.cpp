#include <bits/stdc++.h>
using namespace std;

//creating linked list struct node
struct Node{
    public:
    int data;
    Node* next;

    //constructor
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


//converting array to LL
Node* convertarraytoLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;//moving pointer
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);//temporary node to add next element
        mover->next=temp;//linking prev node address to this new element
        mover=mover->next;//shifting this moving pointer to this new element
    }
    return head;//returning head of this linkedlist
}

//searching an element present in Linkedlist or not
bool searhinLL(Node* head, int target){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==target)return true;
        temp=temp->next;
    }
}

//length of a linkedlist
int lengthofLL(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

int main()
{
    //create a node
    // int arr[3]={3,6,9};
    // Node* y = new Node(arr[2]);
    // cout<<y<<endl;
    // cout<<y->data<<endl;
    // cout<<y->next<<endl;

    //creating a linked list from array and printing the linked list
    // vector<int> arr={2,4,6,8,10,12};
    // Node *head=convertarraytoLL(arr);
    // Node* temp=head;
    // cout<<head->data<<" ";
    // while(temp!=nullptr){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    // }

    //searching an element in linked list
    // vector<int> arr={2,4,6,8,10,12};
    // Node *head=convertarraytoLL(arr);
    // cout<<searhinLL(head,12);

    //finding length of a linked list
    // vector<int> arr={2,4,6,8,10,12};
    // Node *head=convertarraytoLL(arr);
    // cout<<lengthofLL(head);

    return 0;
}
