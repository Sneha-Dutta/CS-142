#include <iostream>
using namespace std;

class Node {
   public:
   int data;
   Node * left;
   Node * right;
   
   Node(int val) {
      data = val;
      left = NULL;
      right = NULL;
   }
};

class BiST {
   public:
   Node * root;
   BiST() {
      root = NULL;
   }
   
   void insert(int value) {
      insertHelper(root, value);
   }
   
   void insertHelper(Node *curr, int value) {
      //Base case if curr is NULL, insert there
      //Node * temp = new Node(value);
      if (root == NULL) {
         root = new Node(value);
      }
      //else compare the curr data with value
      
