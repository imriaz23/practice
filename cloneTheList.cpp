#include<iostream>
#include<unordered_map>

using namespace std;
struct Node{
  int data;
  Node *next,*random;
  Node(int data){
    this->data=data;
    random=next=NULL;
  }
};
// O(n) O(n) HashMap
Node *cloneTheList(Node * head){
  if(!head)
    return NULL;
  unordered_map<Node *,Node*>hashTable;
  Node * curr=head;
  while(curr){
    Node * temp =new Node(curr->data);
    hashTable[curr]=temp;
    curr=curr->next;
  }
  curr=head;
 Node * newHead=hashTable[curr];
  while(curr){
    Node* temp=hashTable[curr];
    temp->next=hashTable[curr->next];
    temp->random=hashTable[curr->random];
    curr=curr->next;
  }
return newHead;
}
Node * cloneTheList2(Node * head){
  if(!head)
    return NULL;
  Node * l1,*l2;
  l1=head;
  while(l1){
    l2 = new Node(l1->data);
    l2->next = l1->random;
    l1->random=l2;
    l1=l1->next;
  }
  Node * newHead=head->random;
  l1=head;
  while(l1){
    l2=l1->random;
    l2->random=l2->next ? l2->next->random : NULL;
    l1=l1->next;
  }
  l1=head;
  while(l1){
    l2=l1->random;
    l1->random=l2->next;
    l2->next=l1->next ? l1->next->random : NULL;
      l1=l1->next;
  }
  return newHead;
}
void print(Node *head){
  if(!head)
    return;
  while(head){
    cout << head->data<<" ";
    head=head->next;
  }
  cout << endl;
}

int main(){
 Node* start = new Node(1);
 start->next = new Node(2);
 start->next->next = new Node(3);
 start->next->next->next = new Node(4);
 start->next->next->next->next = new Node(5);
 start->random=start->next->next;
 start->next->random=start;
 start->next->next->random = start->next->next->next->next;
 start->next->next->next->random=start->next->next->next->next;
 start->next->next->next->next->random = start->next;
 print(start);
 Node* clonedList = cloneTheList(start);
 print(clonedList);
 Node* copiedList = cloneTheList2(start);
 print(copiedList);


  return 0;
}
