//Queue using linked list
//FIFO (First-In-First-Out) 
#include"LinkedList.cpp"
using namespace std;
class QueueLL {
   public:
   Node *front;
   Node *rear;
   LinkedList l1;
   //constructor 
   QueueLL() {
      front=l1.head;
      rear=l1.tail;
   }
   
   //to insert an element at the end of the queue
   void enqueue( int value) {
      l1.insert(value);
      //modify front and rear value
      front = l1.head;
      rear= l1.tail;
   }
   
   //to delete from other end (1st element)
   void dequeue() {
      if(isEmpty()== true) {
         cout << "Queue is already empty " << endl;
      }
      else {
         l1.deleteAt(1);
      }
      //modify front and rear value
      front= l1.head;
      rear=l1.tail;
   }
   
   //to count the number of elements in the queue
   int size() {
      return l1.countItems();
   }
   
   //to display front
   void frontDisp() {
      if (isEmpty() == true) {
         cout << "Queue is empty" << endl;
      }
      else if (isEmpty() == false) {
         cout << "Front value= " << front->data << endl;
      }
   }
   
   //to display rear
   void rearDisp() {
       if (isEmpty() == true) {
         cout << "Queue is empty" << endl;
      }
      else if (isEmpty() == false) {
         cout << "Rear value= " << rear->data << endl;
      }
   }
   
   //to check if queue is empty
   bool isEmpty() {
      if(front == NULL) {
         return true;
      }
      else
         return false;
   }
   
   //to display the queue
   void display() {
      if (isEmpty()== true ) {
         cout << "Queue is empty" << endl;
      }
      else if (isEmpty()== false) {
         l1.display();
      }
   }
};

int main() {
   QueueLL q1;
   for (int i=0; i<=5; i++) {
      q1.enqueue(i);
   }
   q1.display();
   q1.enqueue(7);
   q1.display();
   q1.frontDisp();
   q1.rearDisp();
   cout << "Number of elements=" << q1.size() << endl;
   q1.dequeue();
   q1.display();
}
       
      
      
     

   
