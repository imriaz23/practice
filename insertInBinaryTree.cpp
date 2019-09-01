#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void insertInBinaryTree(struct node *root, int data)
{
    node *newnode = new node(data);
    if (!root)
        root = newnode;
    node *temp;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        else
        {
            temp->left = newnode;
            return;
        }
        if (temp->right)
            q.push(temp->right);
        else
        {
            temp->right = newnode;
            return;
        }
    }
}
void levelOderPrintTree(struct node *root)
{
    node *temp;
    if (!root)
        cout << "empty tree";
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}
int main()
{
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    node *root = new node(55);
    root->left = new node(78);
    root->right = new node(256);
    root->left->left = new node(4);
    root->left->right = new node(52);
    root->right->left = new node(54);
    root->right->right = new node(8956);
    insertInBinaryTree(root, 56893);
    levelOderPrintTree(root);
}