//Linked list for stack and queue
//First include library
#include<iostream>
using namespace std;

//class to create a node (circle)
class Node {
   public:
   //Data
   int data;
   //Pointer which points to next node
   Node * next;
   //Constructor to make pointer to NULL
   Node() {
      next = NULL;
   }
};

class LinkedList {
   //head+circles inside linked with each other
   public:
   //head->node type pointer
   Node * head;
   Node * tail;
   //constructor
   LinkedList() {
      head= NULL;
      tail= NULL;
   }
   
   //function to insert at the end
   void insert(int value) {
      //to add node, make a new node
      Node * temp = new Node;
      //insert data in the node
      temp->data = value;
      //for 1st node
      if (head== NULL) {
         //making the new node as head
         head= temp;
      }
      //other nodes
      else {
         tail->next = temp;
      }
      tail = temp;
   }
   
   //to insert at a particular position
   void insertAt(int value, int pos) {
      //to insert at 1st position
      if (pos==1) {
         //new node to insert
         Node * temp= new Node;
         //insert value
         temp->data = value;
         //moving pointer 
         temp->next = head;
         head = temp;
      }
      //insert at other positions
      else {
         //first reach the node before pos
         Node * current = head;
         int i=1;
         while (i<pos-1) {
            i++;
            current = current->next;
         }
         Node * temp= new Node;
         temp->data = value;
         temp->next = current->next;
         current->next = temp;
      }
   }
   
   //function to delete last element
   void delet() {
      if(head==NULL) {
         cout << "Linked list is already empty" << endl;
      }
      //if list has only one element
      if(head==tail) {
         head= NULL;
         tail= NULL;
         cout << "Linked list became empty" <<endl;
      }
      else {
         Node * temp =tail;
         //move current pointer to node before tail
         Node * current = head;
         while (current->next !=tail) {
            current= current->next;
         }
         current->next = NULL;
         //update tail
         tail= current;
      }
   
   }
   
   //to delete at a particular position
   void deleteAt( int pos) {
      if (pos==1) {
         Node * current= head;
         int temp= head->data;
         current= current->next;
         head = current;
      }
      if (head== NULL) {
         cout << "List is already empty" << endl;
         
      }
      
      else {
         int temp;
         //node just before pos
         Node *a= head;
         //node just after pos
         Node *b=head;
         int i=1, j=1;
         //reach the node just before pos
         while (i<pos-1) {
            i++;
            a=a->next;
         }
         //reach the node just after pos
         while (j<pos+1) {
            j++;
            b=b->next;
         }
         temp = (a->next)->data;
         //a's next is pointed to b
         a->next = b;
      }
   
   }
   
   //display the elements of linked list
   void display() { 
      if (head== NULL) {
         cout << "List is empty" << endl;
      }
      else { 
         Node * current= head;
         while (current != NULL) {
            cout << current->data << "->";
            current= current->next;
         }
         cout << "NULL" << endl;
      }
   }
   
   //count the number of elements
   int countItems() {
      Node * current = head;
      int count=0;
      while (current != NULL) {
         current= current->next;
         count++;
      }
      return count;
   }
};
         
          
      


