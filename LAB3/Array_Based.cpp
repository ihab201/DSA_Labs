#include <iostream>

using namespace std;

class Queue
{ 
private:
    int f, r, n;
    int capacity;
    string *Q;

public:
    Queue(int cap = 10);
    ~Queue();
    int size() const;              // number of items in queue
    bool empty() const;            // is the queue empty?
    string &front() const;         // the front element
    void enqueue(const string &e); // enqueue element at rear
    void dequeue();                // dequeue element at front
    void print();                  // printing the element of the queue
};
Queue::Queue(int cap)
{
    capacity = cap;
    f = r = n = 0;
    Q = new string[capacity];
}
Queue::~Queue()
{
    while (!empty())
        dequeue();
}
int Queue::size() const { return n; }

bool Queue::empty() const { return n == 0; }

string &Queue::front() const
{
    if (!empty())
        return Q[f];
    else
        cout << "the Queue is empty";
        
}
void Queue::enqueue(const string &e)
{
    if (size() != capacity)
    {
        Q[r] = e;
        r = (r + 1) % capacity;
        n++;
    }
    else
    {
        cout << "the queue is full";
        cout << endl;
    }
}
void Queue::dequeue()
{
    if (!empty())
    {
        f = (f + 1) % capacity;
        n--;
    }
    else
    {
        cout << "the Queue is empty";
    }
}
void Queue::print()
{
    cout << "contents of the stack: [ ";
    for (int i = 0; i <= size(); i++)
    {
        cout << Q[i];
        cout << endl;
    }
    cout << "]";
    cout << endl;
}

int main()
{
    char user_option = '\0';
    Queue B(10);
    string a;
    while (user_option != 'q')
    {
        cout << "> Please select an option to proceed: \n"
             << " s: the size of the Queue\n"
             << " e: is the Queue empty \n"
             << " t: get the first element of the Queue withount modifying it \n"
             << " p: enqueue an element to the Queue \n"
             << " r: dequeue an element from the Queue \n"
             << " l: printing the elements of the Queue"
             << " q: to quit the program \n";
        cin >> user_option;
        switch (user_option)
        {
        case 's':
            cout << "the size of the Queue is: " << B.size();
            cout << endl;
            break;
        case 'e':
            cout << "is the Queue empty? " << B.empty();
            break;
        case 't':
            cout << "the front element of the Queue is: " << B.front();
            break;
        case 'p':
            cout << "enter the element you want to enqueue  into the Queue";
            cin >> a;
            B.enqueue(a);
            break;
        case 'r':
            B.dequeue();
            cout << "an element has just been dequeued from the top of the stack\n";
            break;
        case 'l':
            cout << "the element of the Queue are  ";
            B.print();
        case 'q': /*quit*/
            cout << "Quitting program ... ";
            break;
        default:
            cout << "Wrong input ! try again !\n";
            break;
        }
    }
    return 0;
}

