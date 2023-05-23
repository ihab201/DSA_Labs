#include <iostream>

using namespace std;

struct Node {
    int Elem;
    Node* next;
};

class Queue{
    private:
        Node* f, *r;
        int n;
    public: 
        Queue();
        ~Queue();
        int size() const;
        bool empty() const;
        void enqueue(const int& e);
        void dequeue();
        const int& front() const;
        void print() const; 
};

void enqueue_ordered(Queue &Q, int e);
int queue_sum(Queue & Q);

int main(int argc, char const *argv[])
{

    char user_option;
    int temp_int;
    Queue queue;

    // cout<<"queue lists implementation.\n";
    // while (user_option != 'q')
    // {
    //     cout << "> Please select an option to proceed: \n"
    //          << "    e: enqueue new element\n"
    //          << "    d: dequeue element \n"
    //          << "    s: Get Queue size \n"
    //          << "    c: check if Queue is empty \n"
    //          << "    f: Get Front Elemenet \n"
    //          << "    p: print content of queue \n"
    //          << "    q: to quit the program \n";
    //     cin >> user_option;

    //     switch (user_option)
    //     {
    //     case 'e': /*Enqueue*/
    //         cout << "> type the value to push: ";
    //         cin >> temp_int;
    //         queue.enqueue(temp_int);
    //         break;

    //     case 'd': /*Dequeue*/
    //         if(queue.empty()) cout<<"Queue is empty. \n";
    //         else { 
    //             cout << "> the item to be removed is: "<< queue.front()<<endl;
    //             queue.dequeue();
    //         }
    //         break;

    //     case 's': /*get size*/
    //         cout << " size of stack is : " << queue.size() << "\n";
    //         break;

    //     case 'c': /*check if empty*/
    //         if(queue.empty()){
    //             cout<<"queue is empty.\n";
    //         }
    //         else cout<<"queue is not empty.\n";
    //         break;

    //     case 'f': /*Front element*/
    //         if(queue.empty()) cout<<"Queue is empty. \n";
    //         else cout<<"top element: "<<queue.front();
    //         break;
            
    //     case 'p': /*print elements of queue*/
    //         queue.print();
    //         break;

    //     case 'q': /*quit*/
    //         cout << "Quitting program ... ";
    //         break;

    //     default:
    //         cout << "Wrong input ! try again !\n";
    //         break;
    //     }
    //     cout << "\n------------------------------------------\n\n";
    // }
    queue.enqueue(9);
    queue.enqueue(8);
    queue.enqueue(7);
    queue.enqueue(3);
    queue.enqueue(2);
    queue.enqueue(1);
    cout<<"enqueue in ordered value: ";
    cin>> temp_int;
    enqueue_ordered(queue, temp_int);
    cout<<"result: ";
    queue.print();

    cout<<"\nsum is: "<< queue_sum(queue)<< endl;
    cout<<"\n";

    return 0;
}

//Functions implementation.
Queue::Queue(){
    f = NULL;
    r = NULL;
    n = 0;
}
Queue::~Queue(){
    while(!empty()) dequeue();
}

int Queue::size() const{
    return n;
}
bool Queue::empty() const{
    return n == 0;
}
void Queue::enqueue(const int& e){
    Node* tmp = new Node;
    tmp->Elem = e;
    tmp->next = NULL;
    if(empty()){
        f = tmp;
        r = tmp;
    }
    else{
        r->next = tmp;
        r = tmp;
    }
    n++;
}
void Queue::dequeue(){
    if(empty()) cout<<"Queue is empty.\n";
    else{
        if(n == 1){
            delete r;
            r=f=NULL;
        }
        else{
            Node* tmp = f;
            f = f->next;
            delete tmp;
        }
        n--;
    }
}
const int& Queue::front() const{
    return f->Elem;
}
void Queue::print() const{
    Node* tmp = f;
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

//Exercise 2.
void enqueue_ordered(Queue &Q, int e) {
    int dequeued;
    bool enqueued = false;

    cout<< "inside enqueue ordered\n";
    // If queue is empty or e is greater than the front element,
    // then simply enqueue e and return.
    if (Q.empty() || e >= Q.front()) {
        Q.enqueue(e);
        return;
    }

    // Dequeue elements from the queue and enqueue them back
    // in the correct order.
    while (!Q.empty()) {
        dequeued = Q.front();
        Q.dequeue();

        if (e >= dequeued && !enqueued) {
            Q.enqueue(e);
            enqueued = true;
        }

        Q.enqueue(dequeued);
    }

    return;
}

int queue_sum(Queue & Q){
    Queue tmpQueue = Q;
    int sum = 0;

    while(!tmpQueue.empty()){
        sum += tmpQueue.front();
        tmpQueue.dequeue();
    }

    return sum;
}

