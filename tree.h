#pragma once
#include <string>
#include <fstream>
using namespace std;

struct Node {
    Node(char input_value) : value(input_value), left(NULL), right(NULL) {}
    char value;
    Node *left;
    Node *right;
};

class BinaryTree {
public:
    BinaryTree() { _root = NULL; };
    ~BinaryTree() {
        delete[] _root;
        _root = NULL;
    };
    void buildFromString(const char *data);

    string preOrder(Node *a, int check);
    string postOrder(Node* temp, int check);
    string inOrder(Node* temp, int check);
    string levelOrder(Node* temp, int check);
    void general_tree(string &list, Node *a, int check);
private:
    Node *_root;
    Node *_buildFromString(const char *data, int start, int end);
    /////////////////////////////////////////////////////////
    //////  TODO: Add Private members if required ///////////
    void _currentLevel(string& list, Node *a, int level);
    int height(Node* node);//트리의 높이를 확인하는 함수
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
};