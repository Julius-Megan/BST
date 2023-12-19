#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int k) {
	key = k;
	left = nullptr;
	right = nullptr;
	p = nullptr;
}

Node::~Node() {
	cout << "Now destroying node " << key << endl;
}
