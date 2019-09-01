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
void levelOrderTraversalInReverserOrder(struct node *root)
{
    if (!root)
        cout << "empty tree";
    node *temp;
    queue<node *> q;
    stack<node *> s;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
        s.push(temp);
    }
    while (!s.empty())
    {
        cout << s.top()->data;
        s.pop();
    }
}
int main()
{
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    levelOrderTraversalInReverserOrder(root);
}
