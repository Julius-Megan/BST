#pragma once
class Node
{
public:
	int key;
	Node* left;
	Node* right;
	Node* p;

	Node(int);
	~Node();

};

