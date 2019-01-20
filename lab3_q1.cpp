//first include library
#include<iostream>
using namespace std;
class Node{
      public:
      //data
      int dt;
      Node * next;
      Node * prev;
      //constructor to make pointer null 
      Node(int value){
	      next=NULL;
	      prev=NULL;
	      dt=value;
     }
};

class DLL{
      public:
      //head is first pointer
      Node * head;
      //constructor for initial value of head
      DLL(){
       	head=NULL;
      }
      
      //function to add a new element to the end of the list
      void insert(int data){
           //create new node
           Node * temp= new Node(data);
           //if list is empty
           if (head==NULL){
           head=temp;
           }
           //if list has elements
           else {
            //declare a pointer to move last element
            Node * current = head;
            //loop to move the pointer
            while (current->next!=NULL)
            {
              current=current->next;
            }
            //at last node current's next will be temp
            current->next=temp;
            temp->prev=current;
          }

    }
        

        //function to include the position at which insertion happens
	void insertAt(int pos,int data){
		Node * current =head;
		Node * temp = new Node(data);
		int i=1;
                while(i<pos-1){
                i++;
		current =current->next;
               }
		temp->next=current->next;
		current->next=temp;
		temp->next->prev=temp;
		temp->prev=current;
	}
	
        //deletes the element at the end of the list
        void delet(){
		Node * current=head;
		Node * temp ;
		while (current->next->next!=NULL){
		  current=current->next;
		}
		current->next=temp;
		current->next=NULL;
		delete temp;
	}
	//delete element at position pos
	void deleteAt(int pos){
		Node * current =head;
		Node * temp ;
		int i=1;
                while(i<pos-1){
                  i++;
		  current =current->next;
                }
		temp=current->next;
		current->next=current->next->next;
		current->next->prev=current;
		delete temp;
	}

        //To return the number of items in the list
	void CountItems(){
		Node * current = head;
		int count=1;
		while(current->next!=NULL){
		  count++;
                  current=current->next;
                }
                cout << " Number of elements in list= " << count << endl;}



       void display(){
            Node * current=head;
            //defining another pointer for printing reverse order list            
            Node * end;
            cout<<"Linked List :";
            while (current!=NULL) {
             cout << current->dt<<"->";
             //store current in end
             end = current;
             current = current->next;
           }
            cout << endl;
            cout << "Linked List in the reverse order :";
            while(end!=NULL)
            {
              cout << end->dt << "->";
              end =end->prev;
            }
            cout << endl;
          
	}

};	



int main(){
    DLL dll1;
    for (int i=1; i<11; i++) {
      dll1.insert(i);
    }
    dll1.display();
    dll1.delet();
    dll1.display();
    dll1.insertAt(3,5);
    dll1.display();
    dll1.deleteAt(5);
    dll1.display();
    dll1.CountItems();
    
}

