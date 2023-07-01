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
};