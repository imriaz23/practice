#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
    node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
int treeHeight(struct node *root)
{
    if (!root)
        return 0;
    node *temp;
    queue<node *> q;
    q.push(root);
    int height = 0;
    int nodecount;
    while (1)
    {
        nodecount = q.size();
        if (nodecount == 0)
            return height;
        height++;
        while (nodecount > 0)
        {
            temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            nodecount--;
        }
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
    cout << treeHeight(root);
}
