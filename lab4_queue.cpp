//queue using linked list
#include "LinkedList.cpp"
using namespace std;

class queueLL {
   public:
   Node * front;
   LinkedList l1;
   //constructor
   queue() {
   // top will be null, head is also null, so top = head
      front = l1.head;
   }
   //insert on top
   void enqueue(int data) {
      //void insertAt(int pos, int data) {
      l1.insertAt(data,1);
      //top= new_head;
      front = l1.head;
   }
   
   //deletes the end
   void dequeue() {
      //void delet() {
      l1.delet();      
   }
   
   //to check whether the queue is empty
   bool isEmpty() {
      if(front == NULL)
         return true;
      return false;
   }
   //to count number of elements in the queue
   int size () {
      return l1.countItems();
   }
   
   void topDisplay() {
     cout << "Top of Queue is = "<< front->data << endl;
   }
   
   void display() {
      l1.display() ;
   }
};
int main() {
   queue q1;
   
   for (int i=1; i<5; i++) {
      q1.enqueue(i);
   }
   q1.display();
   q1.dequeue();
   q1.display();
   q1.dequeue();
   q1.display();
   q1.dequeue();
   q1.display();
   q1.dequeue();
   q1.display();
   q1.dequeue();
   q1.display();
}
