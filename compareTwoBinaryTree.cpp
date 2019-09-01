#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node*left,*right;
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};
bool compareTwoBinaryTree(struct node*root1,struct node*root2){
    if(!root1 and !root2)
    return true;
    if(!root1 or !root2)
    return false;
    node *temp1,*temp2;
    queue<node*>q1;
    queue<node*>q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty() and !q2.empty()){
        temp1=q1.front();
        temp2=q2.front();
        q1.pop();
        q2.pop();
        if(temp1->data!= temp2->data)
        return false;
        if(temp1->left and temp2->left){
            q1.push(temp1->left);
            q2.push(temp2->left);
        }
        else if(temp1->left or temp2->left)
        return false;
        if(temp1->right and temp2->right){
            q1.push(temp1->right);
            q2.push(temp2->right);
        }
        else if(temp1->right or temp2->right)
        return false;
    }
    return true;
}
int main(){
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    node *root1 = new node(55);
    root1->left = new node(78);
    root1->right = new node(256);
    root1->left->left = new node(4);
    root1->left->right = new node(52);
    root1->right->left = new node(54);
    root1->right->right = new node(8956);
    
    node *root2 = new node(55);
    root2->left = new node(78);
    root2->right = new node(256);
    root2->left->left = new node(4);
    root2->left->right = new node(52);
    root2->right->left = new node(54);
    root2->right->right = new node(8956);
    cout<<compareTwoBinaryTree(root1,root2);
}
