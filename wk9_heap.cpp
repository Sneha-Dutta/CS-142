//first include library
#include<iostream>
using namespace std;

/*

2 Rules for Binary Heap
- Its a complete tree. -> So can use an array
- Either a max-heap or min-heap. 

Array Implementation 
Root - A[0]

Parent Node : Arr[(i-1)/2]
Left Child  : Arr[(2*i)+1]
Right Child : Arr[(2*i)+2]

Functions:
1. GetMin()
2. ExtractMin()
3. DecreaseKey()
4. Insert()
5. Delete()
6. Display()

*/


class BinaryHeap{
    public:
    // Pointer to array of elements
    int * hArr;
    // to store maximum possible size of array
    int mSize;
    // to store current size of array 
    int crSize;

    BinaryHeap(int mSize) {
        //constructor
        hArr = new int[mSize];
        this->mSize = mSize;
        crSize = 0;
    }
    
    //to swap elements
    void swap(int *a, int *b) {
        int temp = *a; 
        *a = *b; 
        *b = temp;
    }
    //to return the index of the parent
    int parent(int i) { 
       return (i-1)/2;
    }
    //to return index of left child
    int left(int i) { 
       return (i*2)+1;
    }
    //to return index of right child
    int right(int i) { 
       return (i*2)+2;
    }
    //minimum element of the heap
    int getMin() { 
       return hArr[0];
    }

    //to insert an element in the heap
    void insert(int value) {
        // Base case
        if(crSize == mSize){
            cout << "Heap Overflow" << endl;
            return;
        }
        // Insert the new key at the end.
        int i = crSize++;
        hArr[i] = value;

        //Check if it breaks the heap property and fix it. 
        //Check it for all hierarchy 
        while (i != 0 && hArr[parent(i)] > hArr[i]) 
        { 
            swap(&hArr[i], &hArr[parent(i)]); 
            i = parent(i); 
        }

    }
    
    //to display the array
    void display() {
        for(int i = 0; i < crSize ; i++){
            cout << hArr[i] << ",";
        }
        cout << endl;
    }

    //to find the minimum 
    int extractMin() {
    
        //base case for empty heap
        if (crSize <= 0) 
            cout << "Empty heap" << endl; 
        //base case for heap having 1 element
        if (crSize == 1) 
        { 
            crSize--; 
            return hArr[0]; 
        } 
    
        // Store the minimum value, and remove it from heap 
        int root = hArr[0]; 
        hArr[0] = hArr[crSize-1]; 
        crSize--; 
        //call MinHeapify on root
        MinHeapify(0); 
        //return the root
        return root; 
    }

    void decreaseKey(int i, int new_val) {
    
        // Algorithm for what happens when reduce the value of an element indexed at i to new_val. Assume new_val to be less than the present value of the element. 
        hArr[i] = new_val; 
        //loop to compare with parent and move up till i==0 or there is no violation
        while (i != 0 && hArr[parent(i)] > hArr[i]) 
        { 
            swap(&hArr[i], &hArr[parent(i)]); 
            i = parent(i); 
        } 
    } 
    
    //to delete the element indexed at i
    void deleteKeyAt(int i)  {   
        if (i>crSize) {
            cout << "Heap underflow" << endl;
        }
        else {
           // Decrease the value to INT_MIN 
           decreaseKey(i, hArr[crSize]); 
           // Call function ExtractMin
           extractMin(); 
        }
    }

    void MinHeapify(int i) { 
        int l = left(i); 
        int r = right(i); 
        int smallest = i; 
        //compare with left and right and replace with the smallest
        if (l < crSize && hArr[l] < hArr[i]) 
            smallest = l; 
        if (r < crSize && hArr[r] < hArr[smallest]) 
            smallest = r; 
        //call MinHeapify at the replaced child
        if (smallest != i) 
        { 
            swap(&hArr[i], &hArr[smallest]); 
            MinHeapify(smallest); 
        } 
    } 

};

//main function
int main(){
    BinaryHeap bh1(20);
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        bh1.display();
    }
    bh1.extractMin();
    bh1.display();
    bh1.deleteKeyAt(3);
    bh1.display();
    cout << endl;
}
