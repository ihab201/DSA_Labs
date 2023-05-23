#include <iostream>

#define MAX_SIZE 100

using namespace std;

class stackArr{
    private: 
        int* arr;
        int capacity; // capacity of the stack
        int t; //index of the top of the stack
    public: 
        stackArr(int cap = MAX_SIZE);
        ~stackArr();
        bool empty() const;
        int size() const;
        void push(const int& e);
        void pop();
        const int& top() const;
        void print() const;
};

int main(int argc, char const *argv[])
{
    char user_option;
    int temp_int;
    unsigned temp_position = 0;
    stackArr arr;

    arr.push(123);
    cout<<"Array Stack implementation.\n";
    while (user_option != 'q')
    {
        cout << "> Please select an option to proceed: \n"
             << "    p: Push new element\n"
             << "    d: Pop element \n"
             << "    s: Get Stack size \n"
             << "    e: check if stack is empty \n"
             << "    t: Get Top Elemenet \n"
             << "    r: print content of stack \n"
             << "    q: to quit the program \n";
        cin >> user_option;

        switch (user_option)
        {
        case 'p': /*Push*/
            cout << "> type the value to push: ";
            cin >> temp_int;
            arr.push(temp_int);
            break;

        case 'd': /*Pop*/
            cout << "> the item to be removed is: "<< arr.top()<<endl;
            arr.pop();
            break;

        case 's': /*get size*/
            cout << " size of stack is : " << arr.size() << "\n";
            break;

        case 'e': /*check if empty*/
            if(arr.empty()){
                cout<<"stack is empty.\n";
            }
            else cout<<"stack is not empty.\n";
            break;

        case 't': /*top element*/
            cout<<"top element: "<<arr.top();
            break;
            
        case 'r': /*print elements of stack*/
            arr.print();
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
    return 0;
}

//Functions implementation.
stackArr::stackArr(int cap){
    arr = new int[cap];
    capacity = cap;
    t = -1;
}
stackArr::~stackArr(){
    delete[] arr;
}

bool stackArr::empty() const{
    return (t == -1);
}
int stackArr::size() const{
    return (t+1);
}
void stackArr::push(const int& e){
    if (size() == capacity) cout<<"Stack is full\n";
    else{
        arr[++t] = e;
    }
}
void stackArr::pop(){
    if(empty()) cout<<"empty stack\n";
    else{
        t--;
    }
}
void stackArr::print() const{
    if(empty()){
        cout<<"empty stack\n";
    }
    else{
        cout<<"Elements in stack:\n";
        for(int i = t; i>= 0; i--){
            cout<<arr[i]<<endl;
        }
    }
}
const int& stackArr::top() const{
    return arr[t];
}