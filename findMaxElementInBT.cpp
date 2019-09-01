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
int findMaxElementInBT(struct node*root){
    int max=INT_MIN;
    node *temp;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(max<temp->data)
        max=temp->data;
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    return max;
}
int main(){
    //freopen("output.txt","w",stdout);
    node *root=new node(55);
    root->left=new node(78);
    root->right=new node(256);
    root->left->left=new node(4);
    root->left->right=new node(52);
    root->right->left=new node(54);
    root->right->right=new node(8956);
    cout<<findMaxElementInBT(root);
}