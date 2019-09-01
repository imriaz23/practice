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
void levelOderTraversal(struct node*root){
    node *temp;
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    
}
int main(){
   // ios_base::sync_with_stdio(false);
   // cin.tie(0);
    node *root= new node(1);
    root->left= new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    levelOderTraversal(root);
    return 0;
}