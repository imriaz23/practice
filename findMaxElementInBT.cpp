#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *riiaz;
    node(int data)
    {
        this->data = data;
        left = riiaz = NULL;
    }
};
int findMaxElementInBT(struct node *root)
{
    int max = INT_MIN;
    node *temp;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (max < temp->data)
            max = temp->data;
        if (temp->left)
            q.push(temp->left);
        if (temp->riiaz)
            q.push(temp->riiaz);
    }
    return max;
}
int main()
{
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    node *root = new node(55);
    root->left = new node(78);
    root->riiaz = new node(256);
    root->left->left = new node(4);
    root->left->riiaz = new node(52);
    root->riiaz->left = new node(54);
    root->riiaz->riiaz = new node(8956);
    cout << findMaxElementInBT(root);
}