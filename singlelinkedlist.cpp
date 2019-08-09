#include<iostream>
using namespace std;
class ListNode {
public:
	int data;
	ListNode* next;
}*head;
void initialize() {
	head = NULL;
}
void insertAtBeginning(int data) {
	//create new node
	ListNode* newNode = new ListNode();
	if (!newNode) {
		cout << "memory error" << endl;
		return;
	}
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}
void printList(ListNode* head) {
	ListNode* current;
	current = head;
	while (current) {
		cout << current->data << "-->";
		current = current->next;
	}
}
void insertAtTheEnd(int data) {
	//test
	//crate a node first
	ListNode* node = new ListNode();
	if (!node) {
		cout << "memory error" << endl;
		return;
	}
	node->data = data;
	ListNode* temp;
	temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = node;
	node->next = NULL;
}
void insert(ListNode** head, int data, int position) {
	ListNode* p, * q = NULL;
	int k = 1;
	ListNode* node = new ListNode();
	//always check memory error
	if (!node) {
		cout << "eror" << endl;
		return;
	}
	node->data = data;
	p = *head;
	//inset at beginning
	if (position == 1) {
		node->next = *head;
		*head = node;
	}
	else {
		while ((p!=NULL) && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}
		node->next = q->next;
		q->next = node;
	}

}
int getLength(ListNode* head) {
	ListNode* current;
	int k = 0;
	current = head;
	while (current != NULL)
	{
		k++;
		current = current->next;

	}
	return k;
}
void deleteAtBeginning(ListNode** head) {
	ListNode* temp;
	temp = *head;
	*head = (*head)->next;
	free(temp);
}
void deleteAtTheEnd(ListNode** head) {
	ListNode* temp1;
	ListNode* temp2;
	temp1=temp2 = *head;
	while (temp2->next) {
		temp1 = temp2;
		temp2 = temp2->next;
	}
	temp1->next = NULL;
	free(temp2);
}
void deleteNode(ListNode** head,int position) {
	//require at least two pointer node
	ListNode* p, *q = NULL;
	int k = 1;
	//always check for empty list
	if (!head) {
		cout << "empty list " << endl;
		return;
	}
	p = *head;
	if (position == 1) {
		*head = (*head)->next;
		free(p);
		return;
	}
	else {
		while ((p) && (k < position)) {
			k++;
			q = p;
			p = p->next;
		}
		if (!p)
			cout << "such position does not exist" << endl;
		else {
			q->next = p->next;
			free(p);
		}

	}
}
void deleteList(ListNode** head)
{
	ListNode* temp1,*temp2=NULL;
	temp1=temp2 = *head;
	while (temp1) {
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
	*head = NULL;
}
int main() {
	initialize();
	insertAtBeginning(13);
	insertAtBeginning(56);
	insertAtBeginning(86);
	insertAtTheEnd(90);
	insert(&head, 53, 7);
	insertAtBeginning(1);
	insertAtTheEnd(2);
	deleteAtBeginning(&head);
	deleteAtTheEnd(&head);
	//deleteNode(&head, 6);
	deleteList(&head);
	cout << getLength(head)<<endl;
	printList(head);
	return 0;
}

