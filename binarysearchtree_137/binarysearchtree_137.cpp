#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//constructor
	Node(string i, Node* l, Node* r) {
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
	Node* ROOT;

	BinaryTree() {
		ROOT = NULL; //Initializing ROOT to null
	}

	void insert(string element) // Insert Node in binary search tree
	{
		Node* newNode = new Node(element, NULL, NULL); // Allocate memory
		newNode->info = element; // Assign value to the data field
		newNode->leftchild = NULL; // Make leftchild NULL
		newNode->rightchild = NULL;// Make rightchild NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode); //Locate the node which will be the parent of node to be inserted

		if (parent == NULL)//if the parent is null (Tree is empty)
		{
			ROOT = newNode;
			return; //Exit
		}
		if (element < parent->info) // If the value in the data field of the new node is less than that of the
		{
			parent->leftchild = newNode; // Make the left child of the parent poin to the newnode
		}
		else if (element > parent->info) { // if value in the data filed of the new node is greater than that of the parent
			parent->rightchild = newNode; //make the right child of the parent point to the newnode
		}
	}

	void search(string element, Node*& parent, Node*& currentNode) {//this fuction searches the currentNODE of the specified Node as well as the current Node of its parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element)) {
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr) {
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr) {
		//Performs the postorder traversal of the tree
		if (ROOT == NULL) {
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL) {
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

int main() {
	BinaryTree obj;
	while (true) {
		cout << "\nMenu" << endl;
		cout << "1. Implement inset operation" << endl;
		cout << "2. Perform inorder traversal" << endl;
		cout << "3. Perform preorder traversal" << endl;
		cout << "4. Perform postorder traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter your Choise (1-5): ";
		char ch;
		cin >> ch;
		cout << endl;

		switch (ch) {
		case'1': {
			cout << "Enter a word: ";
			string word;
			cin >> word;
			obj.insert(word);
			break;
		}
		case'2': {
			obj.inorder(obj.ROOT);
			break;
		}
		case'3': {
			obj.preorder(obj.ROOT);
			break;
		}
		case'4': {
			obj.postorder(obj.ROOT);
			break;
		}
		case'5':
			return 0;
		default: {
			cout << "\nInvalid Option" << endl;
			break;
		}
		}
	}
};