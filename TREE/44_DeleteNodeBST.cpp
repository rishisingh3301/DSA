#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

void preordertrav(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << " ";
    preordertrav(node->left);
    preordertrav(node->right);
}
Node* rightestnode(Node *node)
{
    if(node->right==NULL){return node;}
    return rightestnode(node->right);
}
Node *helper(Node *node)
{
    if(node->left==NULL && node->right==NULL){return NULL;}
    if(node->left==NULL && node->right!=NULL){return node->right;}
    if(node->right==NULL && node->left!=NULL){return node->left;}
    Node* rightchild=rightestnode(node->left);
    rightchild->right=node->right;
    return node->left;
}
Node *deletenode(Node *root, int key)
{
    if (root == NULL)
        return root;
    if (root->data == key)
    {
        return helper(root);
    }
    Node *temp = root;
    while (root)
    {
        if (key > root->data)
        {
            if (root->right != NULL && root->right->data == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
        else
        {
            if (root->left != NULL && root->left->data == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
    }
    return temp;
}

int main()
{
    // creating tree
    /*
                 20
               /    \
              15      28
            /  \     /  \
           14   17  26  37
              /        /  \
             16        29   40
    */
    struct Node *root = new Node(20);
    root->left = new Node(15);
    root->left->left = new Node(14);
    root->left->right = new Node(17);
    root->left->right->left = new Node(16);
    root->right = new Node(28);
    root->right->left = new Node(26);
    root->right->right = new Node(37);
    root->right->right->left = new Node(29);
    root->right->right->right = new Node(40);

    // before deleting
    cout << "Before deleting:";
    preordertrav(root);
    cout << endl;
       Node* newroot = deletenode(root,299);
    cout << "After deleting: ";
       preordertrav(newroot);

    return 0;
}