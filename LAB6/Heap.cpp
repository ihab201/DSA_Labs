#include <iostream>

#define MAX_SIZE 100

using namespace std;

struct heapNode{
    int key, data;
};

class MinHeap{
    private:
        int Arrsize;
        int HSize;
        heapNode* heap;
    public:
        MinHeap(int size);
        ~MinHeap();
        void printHeap(){
            for(int i = 0; i< HSize; i++){
                cout<<"heap["<<i<<"]: ";
                cout<< ""<<heap[i].key <<endl;
            }
        }
        void insert(int key, int data);
        void deleteMin();
        void create(heapNode* arr, int size);
        bool isEmpty();
        heapNode getMin();
};

//Functions declaration.
void insertHelper(heapNode heap[], heapNode node, int HeapSize);

//Exercise 2.
void heapSort(heapNode arr[], int size);

int main(int argc, char const *argv[])
{
    char user_option;
    int temp_int;

    int capacity;
    cout << "Enter heap capacity: ";
    cin >> capacity;

    MinHeap minH(capacity);

    while(user_option != 'q'){
        cout << "> Please select an option to proceed: \n"
             << "    i: Insert element\n"
             << "    d: Delete minimum element \n"
             << "    c: Create heap from array \n"
             << "    g: Get minimum element \n"
             << "    p: Print heapt \n"
             << "    q: to quit the program \n";
        cin >> user_option;

        switch (user_option) {
            case 'i':  /*insert element to the heap*/
                int key, data;
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter data: ";
                cin >> data;
                minH.insert(key, data);
                cout << "Element inserted successfully." << endl;
                break;
            
            case 'd':  /*delete min element of heap*/
                minH.deleteMin();
                cout << "Minimum element deleted." << endl;
                break;
            
            case 'g': /*get min*/
                if (minH.getMin().key != -1) {
                    cout << "Minimum element: key = " << minH.getMin().key << ", data = " << minH.getMin().data << endl;
                }
                break; 
            case 'c':{  /*create a heap from an array*/
                int size;
                cout << "Enter size of array: ";
                cin >> size;

                if (size > capacity) {
                    cout << "Input size exceeds heap capacity." << endl;
                    break;
                }

                heapNode* arr = new heapNode[size];

                cout << "Enter elements (key data):" << endl;
                for (int i = 0; i < size; i++) {
                    int key, data;
                    cin >> key >> data;
                    arr[i].data = data;
                    arr[i].key = key;
                }

                minH.create(arr, size);
                cout << "Heap created from array successfully." << endl;

                delete[] arr;

                break;
            }
            case 'p':  /*print elements of Heap*/
                minH.printHeap();
                break;
            
            case 'q': /*quit*/
                cout << "Quitting program ... ";
                break;

            default:
                cout << "Wrong input ! try again !\n";
                break;
            }
            cout << "\n------------------------------------------\n\n";   
    }

    cout<<"Exercise 2: application heap-sort:\n";
    cout<<"> Enter array size: ";
    cin>>temp_int;
    heapNode arr[temp_int];
    cout<<"\nEnter array elements (key data): \n";
    for(int i = 0; i< temp_int; i++){
        int key, data;
        cin >> key >> data;
        arr[i].data = data;
        arr[i].key = key;
    }

    heapSort(arr, temp_int);
    cout<<"\nResult: ";
    for(int i = 0; i< temp_int; i++){
            cout<<"arr["<<i<<"]: ";
            cout<< ""<<arr[i].key <<endl;
    }

    return 0;
}

MinHeap::MinHeap(int s){
    HSize = 0;
    Arrsize = s;
    if (Arrsize > MAX_SIZE){
        heap = new heapNode[MAX_SIZE];
    }
    else {
        heap = new heapNode[Arrsize];
    }
}
MinHeap::~MinHeap(){
    delete[] heap;
}

void MinHeap::insert(int key, int data){
    heapNode tmp = { key, data };
    heap[HSize] = tmp;
    if (HSize > 0){
        insertHelper(heap, heap[HSize], HSize);
    }
    HSize++;
}
void MinHeap::deleteMin() {
    if (HSize == 0) {
        cout << "Heap is empty, unable to delete." << endl;
        return;
    }

    heap[0] = heap[HSize - 1];
    HSize--;

    int currentIndex = 0;
    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;

    while (leftChildIndex < HSize) {
        int smallerChildIndex = leftChildIndex;
        if (rightChildIndex < HSize && heap[rightChildIndex].key < heap[leftChildIndex].key) {
            smallerChildIndex = rightChildIndex;
        }

        if (heap[currentIndex].key <= heap[smallerChildIndex].key) {
            break;
        }

        swap(heap[currentIndex], heap[smallerChildIndex]);
        currentIndex = smallerChildIndex;
        leftChildIndex = 2 * currentIndex + 1;
        rightChildIndex = 2 * currentIndex + 2;
    }
}
void MinHeap::create(heapNode* arr, int size){
    if (size > Arrsize) {
        cout << "Input size exceeds heap capacity." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        heap[i] = arr[i];
    }

    HSize = size;

    for (int i = (HSize - 1) / 2; i >= 0; i--) {
        int currentIndex = i;
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;

        while (leftChildIndex < HSize) {
            int smallerChildIndex = leftChildIndex;
            if (rightChildIndex < HSize && heap[rightChildIndex].key < heap[leftChildIndex].key) {
                smallerChildIndex = rightChildIndex;
            }

            if (heap[currentIndex].key <= heap[smallerChildIndex].key) {
                break;
            }

            swap(heap[currentIndex], heap[smallerChildIndex]);
            currentIndex = smallerChildIndex;
            leftChildIndex = 2 * currentIndex + 1;
            rightChildIndex = 2 * currentIndex + 2;
        }
    }
}
heapNode MinHeap::getMin() {
    if (HSize == 0) {
        cout << "Heap is empty, unable to get minimum." << endl;
    }

    return heap[0];
}
bool MinHeap::isEmpty(){
    return (HSize == 0);
}

// Function to perform heap-sort on an array using the implemented heap
void heapSort(heapNode arr[], int size) {
    MinHeap minHeap(size);

    // Insert elements into the heap
    for (int i = 0; i < size; i++)
        minHeap.insert(arr[i].key, arr[i].key);

    // Extract elements from the heap and update the array
    for (int i = 0; i < size; i++) {
        heapNode minElement = minHeap.getMin();
        arr[i] = minElement;
        minHeap.deleteMin();
    }
}

//Helper Functions.
void insertHelper(heapNode heap[], heapNode node, int HeapSize){
    for(int i = HeapSize; i > 0; i--){
        int parentIndex = (i-1)/2;
        if(heap[i].key < heap[parentIndex].key){
            heapNode tmp = heap[i];
            heap[i] = heap[parentIndex];
            heap[parentIndex] = tmp;
            insertHelper(heap, heap[parentIndex], HeapSize);
        }
    }
}