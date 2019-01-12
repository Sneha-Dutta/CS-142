#include<iostream>
using namespace std;

class Node {
     public:
     //Data
     int dt;
     //Pointer to the next Node
     Node * next;
     //Constructor that makes ptr to NULL
     Node() {
       next = NULL;
     }
};

class LinkedList{
     //Head+Circles inside linked with each other
     public:
     //Head -> Node type ptr
     Node * head;
     Node * tail;
     //Construct
     LinkedList() {
       head = NULL;
       tail = NULL;
     }
     //Circles inside linked with each other
     //Rules how circles will be linked

     //Insert
     void insert(int data) {
       //If 1st node is added
       Node * temp = new Node;
       //Insert value in the node
       temp->dt = data;
       //1st node only
       if(head == NULL) {
         head = temp;
       }
       //Any other node only 
       else {
         tail->next = temp;
       }
       tail = temp;
     }
     // A->B = C , means A is a pointer, find B inside A and put value C in B
     void insertAt(int pos, int data) {
       //Reach the place before the position
       Node * current = head;
       int i=1;
       while (i < pos-1) {
         i++;
         current = current->next;
       }
       //Create a node
       Node * temp = new Node;
       temp -> dt = data;
       
       temp->next = current->next;
       current->next = temp;
       
       //Update the code for 1st position
       if(i>pos) {
         cout << "Linked list does not have that many elements" << endl;
       }
     }
     //Deletion of last element
     void delet() {
       //store the tail in temp
       Node * temp = tail;
       //before tail has to point to null
       Node * current = head;
       while(current->next != tail) {
         current= current->next;
       }
       current->next = NULL;
       
       //update tail
       tail = current;
       //delete temp
       delete temp;
     }
     //delete at a specific position
     void deleteAt(int pos) {
       //if linked list is empty
       if(head== NULL) {
         return ; }
       Node * temp= head;
       if(pos == 0) {
         head= temp-> next;
         return ;
         }
       for(int i=0;temp != NULL && i<pos-1; i++ ) {
         temp= temp->next;
       }
       //if position is more than number of nodes
       if(temp==NULL || temp->next== NULL)
       return ;
       //Pointer to the next of the node to be deleted
       Node * next= temp->next->next;
       temp->next= next;
     }
     //To count no. of itemes in linked list
     int countItems() {
       int count =0;
       Node * current = head;
       while(current != NULL) {
         count++;
         current= current->next;
       }
       return count;
     }
     //Display
     void display() {
       Node * current = head;
       while(current != NULL) {
         cout << current->dt << "->";
         current= current->next;
       }
       cout << endl;
     }

};

int main() {
     LinkedList l1;
     l1.insert(1);
     l1.insert(2);
     l1.insert(3);
     l1.insert(4);
     l1.display();
     l1.delet();
     l1.display();
     l1.insertAt(2,3);
     l1.display();
     l1.deleteAt(2);
     l1.display();
     cout << "The number of items in linked list is= " << l1.countItems() << endl; 
     return 0;
}

