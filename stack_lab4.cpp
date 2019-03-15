#include <iostream>
#include "lab2_q1.cpp"
using namespace std;

class Stack {
   public:
   Node * top;
   LinkedList l1;
   
   Stack() {
      // top will be null, head is also null, so top = head
      top = l1.head;
   }
   //Pushes on top
   void push(int value) {
      //void insertAt(int pos, int data) {
      l1.insertAt(1, int data);
      //top= new_head;
      top= l1.head;
   }
   
   //Pops the top
   void pop() {
      //void deleteAt(int pos) {
      l1.deleteAt(1);
      //top= new head
      top= l1.head;
   }
   
   bool isEmpty() {
      if(top == NULL)
         return true;
      return false;
   }
   
   int size () {
      return countItems();
   }
   
   void topDisplay() {
   
   }
   
   void display() {
      l1.display() ;
   }
};

int main() {
   Stack s1;
   
   for (int i=0; i<5; i++) 
      s1.push(i);
   s1.display();
   s1.pop();
   s1.display();
   s1.pop();
   s1.display();
   s1.pop();
   s1.display();
   s1.pop();
   s1.display();
}
