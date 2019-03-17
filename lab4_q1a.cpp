//Stack using linked list
#include"LinkedList.cpp"
using namespace std;

class StackLL {
   public:
   Node * top;
   LinkedList l1;
   //constructor to make top of stack as tail of linked list
   StackLL() {
      top= NULL;
   }

   //pushes (inserts) on top
   void push(int value) {
      //void insertAt(int value, int pos) 
      l1.insertAt(value,1);
      //modify the top= new_head;
      top= l1.head;
   }

   //pops (deletes) the top
   void pop() {
      if (isEmpty() == true) {
         cout << "Stack is empty" << endl;
      }
      else {
         //void deleteAt(int pos)
         l1.deleteAt(1);
         //top= new_head;
         top= l1.head;
      }
   }

   //function to check if stack is empty
   bool isEmpty() {
      if (top== NULL) {
         return true;
      }
      else {
         return false;
      }
   }

   //function to count number of elements in the stack
   int size() {
      int ct= l1.countItems();
      return ct;
   }

   //function to display top of the stack
   void topDisplay() {
      if (isEmpty() == true) {
         cout << "Stack is empty " << endl;
      }
      else {
         cout << "Top of the stack= " << top->data << endl;
      }
   }

   //to display the elements in the stack
   void display() {
      if (isEmpty() == true) {
         cout << "Stack is empty " << endl;
      }
      else {
         l1.display();
      }
   }
};

//main function 
int main() {
   StackLL s1;
   for (int i=0; i<5; i++) {
      s1.push(i);
   }
   s1.display();
   s1.topDisplay();
   cout << "Number of elements=" << s1.size() << endl;
   s1.pop();
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
         
