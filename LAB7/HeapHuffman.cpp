#include <iostream>
#include <queue>
#include <unordered_map> //Hash Table


#define MAX_SIZE 100

using namespace std;

struct huffman{
    double freq;
    char c;
    huffman* left, *right;
};

class MinHeap{
    private:
        int Arrsize;
        int HSize;
        huffman** heap;
    public:
        MinHeap(int size);
        ~MinHeap();
        void printHeap(){
            for(int i = 0; i< HSize; i++){
                cout<<"heap["<<i<<"]: ";
                cout<< ""<<heap[i]->freq <<endl;
            }
        }
        void insert(huffman* huf);
        void deleteMin();
        void create(huffman** arr, int size);
        bool isEmpty() const;
        int getSize() const;
        huffman* getMin();
};
//Functions declaration.
void insertHelper(huffman** heap, huffman* node, int HeapSize);

class Huffman{
    private: 
        int size;
        MinHeap minH  = MinHeap(size);
        huffman* head;
        unordered_map<char, string> encodingTable; /* hash table to store the 
         alphabets and their codes */

    public:
        Huffman(int size);
        ~Huffman();
        void traverseTree() const;
        void insert(huffman* a);
        void run();
        void code();
        string encode(const string& text) const;
        string decode(const string& encodedText) const;
        
};
/* Huffman Helper Functions */
void levelOrderHelper(huffman* root);
void codingHelper(huffman* root, string str,  unordered_map<char, string>& encodingTable);

int main(int argc, char const *argv[])
{
    
    int temp_int;
    char user_input_char;
    double user_input_freq;
    cout<<"> Enter number of charecters: ";
    cin >> temp_int;
    Huffman huf(temp_int);
    cout<< "Enter the charecters and their frequenecies (char freq): \n";
    for(int i = 0; i< temp_int; i++){
        huffman* tmp = new huffman;
        cin >>user_input_char >> user_input_freq;
        tmp->freq = user_input_freq;
        tmp->c = user_input_char;
        huf.insert(tmp);
    }

    huf.run();
    huf.traverseTree();
    huf.code();
    
    string plainText;
    cout << "\nEncoding: abcdefg";
    plainText = "abcdefg";
    string encodedText = huf.encode(plainText);
    cout << "\nEncoded text: " << encodedText << endl;

    string compressedText;
    cout << "\nDecoding...";
    compressedText = "00100001010011000110111";
    string decodedText = huf.decode(compressedText);
    cout << "\nDecoded text: " << decodedText << endl;

    return 0;
}

/* Huffmane */
Huffman::Huffman(int size){
    this->size = size;
    minH = MinHeap(size);
    head = NULL;
}
Huffman::~Huffman(){
    delete head;
}

void Huffman::insert(huffman* a){
    huffman* tmp = new huffman;  // Allocate memory
    tmp->left = tmp->right = NULL; 
    tmp->freq = a->freq;  
    tmp->c = a->c;  
    minH.insert(tmp);
}
void Huffman::run(){
    if (minH.getSize() < 2) {
        head = minH.getMin();
        return;
    }
    else {
        huffman* firstMin, *secondMin;
        huffman* node = new huffman;  // Allocate memory

        firstMin = minH.getMin();
        minH.deleteMin();

        secondMin = minH.getMin();
        minH.deleteMin();

        node->c = '-';
        node->freq = firstMin->freq + secondMin->freq;
        node->left = firstMin;
        node->right = secondMin;

        minH.insert(node);
        head = minH.getMin();

        run();
    }
}
void Huffman::traverseTree() const{
    cout<<" -huffman tree traverse in level Order: \n";
    levelOrderHelper(head);
}
void Huffman::code(){
    cout<<" - Huffman codes for alphabets: \n";
    codingHelper(head, "", encodingTable);
}

string Huffman::encode(const string& text) const {
    string encodedText;
    for (char c : text) {
        if (encodingTable.find(c) != encodingTable.end()) {
            encodedText += encodingTable.at(c);
        } else {
            cout << "Error: Character '" << c << "' cannot be encoded." << endl;
        }
    }
    return encodedText;
}
string Huffman::decode(const string& encodedText) const {
    string decodedText;
    huffman* current = head;
    for (char c : encodedText) {
        if (c == '0' && current->left != nullptr) {
            current = current->left;
        } else if (c == '1' && current->right != nullptr) {
            current = current->right;
        }

        if (current->left == nullptr && current->right == nullptr) {
            decodedText += current->c;
            current = head;
        }
    }
    return decodedText;
}



/* Min Heap Functions */
MinHeap::MinHeap(int s){
    HSize = 0;
    Arrsize = s;
    if (Arrsize > MAX_SIZE){
        heap = new huffman*[MAX_SIZE];
    }
    else {
        heap = new huffman*[Arrsize];
    }
}
MinHeap::~MinHeap(){
    delete[] heap;
}

void MinHeap::insert(huffman* huf){
    
    heap[HSize] = huf;
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
        if (rightChildIndex < HSize && heap[rightChildIndex]->freq < heap[leftChildIndex]->freq) {
            smallerChildIndex = rightChildIndex;
        }

        if (heap[currentIndex]->freq <= heap[smallerChildIndex]->freq) {
            break;
        }

        swap(heap[currentIndex], heap[smallerChildIndex]);
        currentIndex = smallerChildIndex;
        leftChildIndex = 2 * currentIndex + 1;
        rightChildIndex = 2 * currentIndex + 2;
    }
}
void MinHeap::create(huffman** arr, int size){
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
            if (rightChildIndex < HSize && heap[rightChildIndex]->freq < heap[leftChildIndex]->freq) {
                smallerChildIndex = rightChildIndex;
            }

            if (heap[currentIndex]->freq <= heap[smallerChildIndex]->freq) {
                break;
            }

            swap(heap[currentIndex], heap[smallerChildIndex]);
            currentIndex = smallerChildIndex;
            leftChildIndex = 2 * currentIndex + 1;
            rightChildIndex = 2 * currentIndex + 2;
        }
    }
}
huffman* MinHeap::getMin() {
    if (HSize == 0) {
        cout << "Heap is empty, unable to get minimum." << endl;
    }

    return heap[0];
}
bool MinHeap::isEmpty() const{
    return (HSize == 0);
}
int MinHeap::getSize() const{
    return HSize;
}
//Helper Functions.
void insertHelper(huffman** heap, huffman* node, int HeapSize){
    for(int i = HeapSize; i > 0; i--){
        int parentIndex = (i-1)/2;
        if(heap[i]->freq < heap[parentIndex]->freq){
            huffman* tmp = heap[i];
            heap[i] = heap[parentIndex];
            heap[parentIndex] = tmp;
            insertHelper(heap, heap[parentIndex], HeapSize);
        }
    }
}

void levelOrderHelper(huffman* root){
    if (root == NULL) {
        cout<<"Error: root not found\n";
        return;
    }
    queue<huffman*> q;
    q.push(root);
    while (!q.empty()) {
       root = q.front();
        cout << root->freq << " ";
        cout << root->c << endl;
        q.pop();
        if (root->left != NULL) {
            q.push(root->left);
        }
        if (root->right != NULL) {
            q.push(root->right);
        }
    }
}
void codingHelper(huffman* root, string str,  unordered_map<char, string>& encodingTable){
    if(!root) return;

    if(root->left ==  NULL && root->right == NULL){
        encodingTable[root->c] = str;
        cout << root->c << ": " << str << "\n";
    }

    codingHelper(root->left, str+ "0", encodingTable);
    codingHelper(root->right, str+ "1", encodingTable);
}
