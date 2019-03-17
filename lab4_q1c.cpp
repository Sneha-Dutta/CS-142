//Stack using arrays
//First include library
#include <iostream>
using namespace std;

class Stack {
	public:
	int top;
	int arr[100];

	//construct
	Stack() {
		top=-1;
	}
	
	//inserts at the end
	void * push(int val) {
	   if (top>100) {
	      cout << "Stack overflow" << endl;
	   }
	   else {
	      top=top+1;
	      arr[top]=val;
	   }
	}
	
	//deletes last element
	void * pop(){
		if (top<0) {
			cout << "Stack underflow" << endl;
		}
		else {
			top=top-1;
		}
	}

	//displays the elements of stack
	void display() {
		if (isEmpty()==true) {
			cout << "Stack is empty" << endl;
		}
		else {
			for (int i=0; i<=top; i++) {
				cout << arr[i] << ",";
			}
			cout << endl;
		}
	}

	//to check if stack is empty
	bool isEmpty(){
		if(top==-1) {
		   return true;
		}
		return false;
	}

	//returns the number of elements in the stack
	int size(){
		return top+1;
	}

	//displays top element of stack
	void top_display(){
		if (isEmpty()==false){
			cout << "The top of Stack =" << arr[top] << endl;
		}
		else {
			cout << "Stack is empty" << endl;
		}
	}
};
//main function
int main(){
   Stack s1;
   for (int i=1; i<8; i++) {
      s1.push(i);
   }
   s1.display();
   s1.top_display();
   cout << "No. of elements in stack= " << s1.size() << endl;
   s1.pop();
   s1.display();
   s1.push(10);
   s1.display();
   return 0;
	
}
