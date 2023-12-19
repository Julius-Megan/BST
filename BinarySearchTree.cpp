#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Node.h"


using namespace std;

vector<Node*> binaryTree;
Node* root = nullptr;


void treeInsert(Node* T, Node* z) {
    auto x = T;
    Node* y = nullptr;
    while (x != nullptr) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    
    z = y;

    if (y == nullptr) {
        T = z;

    }
    else if (z->key < y->key) {
        y->left = z;

    }
    else {
        y->right = z;
    }

  

}

void preOrder(Node* n) {
    if (n != nullptr) {
        cout << (n->key);
        preOrder(n->left);
        preOrder(n->right);

    }
}

void inOrder(Node* n) {
    if (n != nullptr) {
        inOrder(n->left);
        cout << (n->key);
        inOrder(n->right);
    }
}

void postOrder(Node* n) {
    if (n != nullptr) {
        postOrder(n->left);
        postOrder(n->right);
        cout << n->key;
    }
}

void clearTree(Node* jin) {
    if (jin != nullptr) {
        clearTree(jin->left);
        clearTree(jin->right);
        delete jin;
    }
}


int main(int argc, char** argv)
{
    //We send a warning if they forget to input the filename
    if (argc == 1) {
        cout << "You forgot the commandline parameter\n";
        exit(0);
    }

    //This is how we read the file. By putting the filename in the commandline argument.
    //An error message is also sent, just in case the file location is incorrect.
    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "could not locate file" << argv[1] << endl;
        exit(0);
    }

    vector<Node*> binaryTree;

    string line1;
    getline(ifs, line1);
    auto n = stoi(line1);




    for (auto x = 0; x < n-1; x++) {
        string line;
        getline(ifs, line);
        

       
        stringstream ss(line); // Create a stringstream from the line
        string word;
        int key;

        ss >> word;
        ss >> key;


        if (word == "ADD") {
            Node* n = new Node(key);
            binaryTree.push_back(n);
            //cout << "insert this to our tree. What? " << word << " key = " << key << endl;
            treeInsert(binaryTree[0], n);
        }

        else if (word == "FIND") {
            cout << "Find " << "this number = " << key << endl;
        }
        else if (word == "INORDER") {
            inOrder(binaryTree[0]);
            cout << endl;
        }
        else if (word == "PREORDER") {
            preOrder(binaryTree[0]);
            cout << endl;
        }
        else if (word == "POSTORDER") {
            postOrder(binaryTree[0]);
            cout << endl;
        }
        else if (word == "CLEAR") {
            cout << "CLEAR " << endl;
        }


        
        

        //cout << word << " key= " << key << endl;
        
    }


}

