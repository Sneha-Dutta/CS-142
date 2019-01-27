#include<iostream>
using namespace std;

//Creating a new node
class Node{
   public:
   //initialise variable to store data
   int dt;
   //pointer to the next node
   Node * next;
   //Construct that makes the pointer to NUll
   Node() {
      next= NULL;
      //assign the entered value to data
      
   }
};

class Csll {
   public:
   Node * head;
   Node * tail;
   Csll(){
      head= NULL;
      tail= head;
   }
   
   //To insert at the end of the list
   void insert( int value) {
      //Create a new node to insert the value
      Node * temp= new Node;
      temp->dt = value;
      //Check if the list is empty
      if(head == NULL) {
         head = temp;
      }
      else {
         Node * current = head;
         while ( current->next != head)
            current = current->next;
         current->next= temp;
      }
      temp->next = head;
   }
   //includes the position at which insertion happens
   void insertAt(int value, int pos) {
      Node * current = head;
      int i=1;
      while (i<pos-1) {
        i++;
        current= current->next;
      }
      Node * temp = new Node;
      temp->dt = value;
      temp->next = current->next;
      current->next = temp;
   }
   
   //deletes the element at the end of the list
   void delet() {
      //pointer to point to head and tail
      Node * current = head;
      Node * temp = tail;
      int i=1;
      while ( current->next != tail) {
         current = current->next;
      }
      current->next->next = NULL;
      current->next= head;
      tail= current;
      delete temp;
   }
   
   //deletes the element at the position pos
   void deleteAt(int pos) {
      Node * temp = head;
      if (pos==1) {
         head = temp->next;
         delete temp;
         return;
      }
      //if pos is not 1
      for(int i=1; i<pos-1; i++) {
         temp= temp->next;
      }
      Node * tem= temp->next;
      temp->next= tem->next;
      delete tem;
   }
   
   //returns the number of items in the linked list
   void countItems() {
      Node * tem= head;
      int i=0;
      while (tem!= NULL) {
         i++;
         tem= tem->next;
      }
      cout << "Number of elements in the list= " << i << endl;
      return;
   
   }
   
   //Display the elements in linked list
   void display() {
      Node * current = head;
      if (current ==NULL) {
         cout << "No elements in the list" << endl;
         return;
      }
      //Stopping at head
      while(current->next != head) {
         cout << current->dt << "->";
         current = current->next;
      }
      //Printing the last element
      cout << current->dt;
      cout << endl;
   }
};

//main function
int main() {
   Csll csll1;
   for(int i=1; i<11; i++) {
      csll1.insert(i);
   }
   csll1.display();
   csll1.insertAt(4,8);
   csll1.display();
   csll1.delet();
   csll1.display();
   csll1.deleteAt(6);
   csll1.display();
   csll1.countItems();
}
