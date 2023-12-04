#include "tree.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/* This is given function. DO NOT MODIFY THIS FUNCTION */
int findIndex(const char *str, int start, int end) {
  if (start > end)
    return -1;

  string s;

  for (int i = start; i <= end; i++) {

    // if open parenthesis, push it
    if (str[i] == '(')
      s.push_back(str[i]);

    // if close parenthesis
    else if (str[i] == ')') {
      if (s.back() == '(') {
        s.pop_back();

        if (!s.length())
          return i;
      }
    }
  }
  // if not found return -1
  return -1;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
Node *BinaryTree::_buildFromString(const char *data, int start, int end) {
  if (start > end)
    return NULL;

  Node *root = new Node(data[start]);
  int index = -1;

  if (start + 1 <= end && data[start + 1] == '(')
    index = findIndex(data, start + 1, end);

  if (index != -1) {
    root->left = _buildFromString(data, start + 2, index - 1);
    root->right = _buildFromString(data, index + 2, end - 1);
  }
  return root;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void BinaryTree::buildFromString(const char *data) {
  Node *root = _buildFromString(data, 0, strlen(data) - 1);
  _root = root;
}

void BinaryTree::general_tree(string &list, Node *a, int check){
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
  if(check==0)
  {  a=_root;
   list += a->value;
    if (!(a->left == NULL))  {
    general_tree(list, a->left, check+1);
     }
    if (!(a->right == NULL)) {
    general_tree(list, a->right, check);
     }
  }
  else{
  list += '(';
  list += a->value;
  if (!(a->left == NULL))  {
    general_tree(list, a->left, check+1);
  }
  list += ')';
  if (!(a->right == NULL)) {
    general_tree(list, a->right, check);
    }
  }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

string BinaryTree::levelOrder(Node*temp, int check) {
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if(check==0)
      temp=_root;
    string list="";

    int h=height(temp);
    int i;
    for(i=1;i<=h;i++){
      _currentLevel(list, temp, i);
    }
    return list;
  

    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

//트리의 높이를 확인하는 함수
int BinaryTree::height(Node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void BinaryTree::_currentLevel(string& list,Node *a, int level){
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if(a==NULL)
      return;
    if(level==1)
    { list+=a->value;
      list+=" ";
    }
    else if(level>1){
      _currentLevel(list,a->left, level-1);
      _currentLevel(list,a->right, level-1);
    }
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

string BinaryTree::preOrder(Node* temp, int check) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  string list="";
  if(check==0)  
    temp=_root;
  if(temp){
    list+= temp->value;
    list+=" ";
    list+=preOrder(temp->left, 1);
    list+=preOrder(temp->right, 1);
  }
  return list;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::postOrder(Node* temp, int check) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  string list="";
  if(check==0)  
    temp=_root;
  if(temp){
    list+=postOrder(temp->left, 1);
    list+=postOrder(temp->right, 1);
    list+= temp->value;
    list+=" ";
  }
  return list;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::inOrder(Node* temp, int check) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  string list="";
  if(check==0)  
    temp=_root;
  if(temp){
    list+=inOrder(temp->left, 1);
    list+= temp->value;
    list+=" ";
    list+=inOrder(temp->right, 1);
  }
  return list;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}
