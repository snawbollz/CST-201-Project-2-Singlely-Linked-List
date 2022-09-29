//Brian Macias
//CST-201
//This is my own work

#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
};
struct node* head = NULL;

/*class myList() {
	head = NULL;
};*/

void insertFront(int newData) {
	struct node* newNode = new node;
	newNode->data = newData;
	newNode->next = head;
	head = newNode;
}

void insertEnd(int newData) {
	struct node* newNode = new node;
	struct node* temp = head;
	newNode->data = newData;
	newNode->next = NULL;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertPos(int pos, int newData) {
	struct node* newNode = new node;
	struct node* temp = head;
	struct node* previous = new node;
	int position = pos;
	newNode->data = newData;

	for (int i = 1; i < position; i++) {
		previous = temp;
		temp = temp->next;
	}
	previous->next = newNode;
	newNode->next = temp;
}

void deleteNode(int newData) {
	struct node* temp = head;
	struct node* previous = new node;

	if (temp != NULL && temp->data == newData) {
		head = temp->next;
		delete(temp);
	}

	while(temp != NULL && temp->data != newData) {
		previous = temp;
		temp = temp->next;
	}
	previous->next = temp->next;
	delete(temp);
}

void front() {
	struct node* temp;
	temp = head;
	cout << temp->data<< endl;
}

void back() {
	struct node* temp;
	temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	cout << temp->data << endl;
}

void insertVal(int newData) {
	struct node* newNode = new node;
	struct node* temp;
	temp = head;
	while (temp->data <= newData) {
		temp = temp->next;
	}
	temp->next = newNode;
}

void display() {
	struct node* temp;
	temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	insertFront(10);
	insertFront(20);
	insertFront(30);
	insertFront(40);
	insertEnd(60);
	
	insertPos(3, 15);
	display();
	front();
	back();
	insertVal(25);

	deleteNode(30);
	display();

	return 0;
}