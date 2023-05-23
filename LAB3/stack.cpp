#include <iostream>
#include<stack>

//Stack: Last-In-First-Out.

using namespace std;

class Stack;
struct node {
    char Elem;
    node* next;
};

class Stack {
    private:
        node* head; 
        int n; //number of element.
    public: 
        Stack();
        ~Stack();
        bool empty() const;
        int size() const;
        void push(const char& e);
        void pop();
        const char& top() const;
        void print() const;
};

int main(int argc, char const *argv[])
{
    char user_option;
    char temp_char;
    //unsigned temp_position = 0;
    Stack stk;

    cout<<"Stack lists implementation.\n";
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
            cin >> temp_char;
            stk.push(temp_char);
            break;

        case 'd': /*Pop*/
            cout << "> the item to be removed is: "<< stk.top()<<endl;
            stk.pop();
            break;

        case 's': /*get size*/
            cout << " size of stack is : " << stk.size() << "\n";
            break;

        case 'e': /*check if empty*/
            if(stk.empty()){
                cout<<"stack is empty.\n";
            }
            else cout<<"stack is not empty.\n";
            break;

        case 't': /*top element*/
            cout<<"top element: "<<stk.top();
            break;
            
        case 'r': /*print elements of stack*/
            stk.print();
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
    //stk.push('A');
    return 0;
}

//Functions implementation.
Stack::Stack(){
    head = nullptr;
    n = 0;
}
Stack::~Stack(){
    while(!empty()) pop();
}

bool Stack::empty() const{
    return (head == nullptr);
}
int Stack::size() const{
    return n;
}
void Stack::push(const char& e){
    node* tmp = new node;
    tmp->Elem = e;
    tmp->next = head;
    head = tmp;
    ++n;
}
void Stack::pop(){
    if(empty()) cout<<"Stack is empty.\n";
    else{
        node* tmp = head;
        head = tmp->next;
        delete tmp;
        --n;
    }
}
const char& Stack::top() const{
    return head->Elem;
}
void Stack::print() const{
    node* tmp = head;
    if (empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack contents:" << endl;
        while (tmp != NULL) {
            cout << tmp->Elem << endl;
            tmp = tmp ->next;
        }
    }
}