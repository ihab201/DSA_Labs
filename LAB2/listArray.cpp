#include <iostream>
#include <cstring>

#define MAX_SIZE 100
#define DIRECTION_BACKWARD 0
#define DIRECTION_FORWARD 1

using namespace std;

typedef struct{
    string ar[MAX_SIZE];
    unsigned size;
}list;

//Functions decalaration
void init(list &l);
void insert(list &l, string item, unsigned position);
void remove(list &l, unsigned position);
int search(list l, string item);
void traverse(list l, unsigned direction);

int main(int argc, char const *argv[])
{
    char user_option;
    char temp_str[MAX_SIZE];
    unsigned temp_position = 0;
    list l;

    init(l);

    while (user_option != 'q')
    {
        cout << "> Please select an option to proceed: \n"
             << "    i: insert new element\n"
             << "    d: delete an element \n"
             << "    s: search for index of an element \n"
             << "    f: traverse list forward \n"
             << "    b: traverse list backward \n"
             << "    q: to quit the program \n";
        cin >> user_option;

        switch (user_option)
        {
        case 'i': /*insert*/
            cout << "> type the position & name to insert: ";
            cin >> temp_position >> temp_str;
            insert(l, temp_str, temp_position);
            break;

        case 'd': /*delete*/
            cout << "> type item position to delete: ";
            cin >> temp_position;
            remove(l, temp_position);
            break;

        case 's': /*serach and get index*/
            cout << "> type the name to search for: ";
            cin >> temp_str;
            cout << temp_str << " index is : " << search(l, temp_str) << "\n";
            break;

        case 'f': /*traverse forward*/
            traverse(l, DIRECTION_FORWARD);
            break;

        case 'b': /*traverse backward*/
            traverse(l, DIRECTION_BACKWARD);
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

void init(list &l){
    l.size = 0;
}
//Functions implementations.

void insert(list &l, string item, unsigned position){
    if(l.size == MAX_SIZE) cout<<"List is full \n";
    else {
        if(position> l.size){
            cout<< "no such position \n";
        }
        else {
            for(int i = l.size ; i> position; i--){
                l.ar[i+1] = l.ar[i];
            }
            l.ar[position] = item;
            l.size++;
        }
    }
}

void remove(list &l, unsigned position){
    if(l.size == 0) cout<< "list is empty \n";
    else{
        if (position >= l.size) cout<<"No such position: "<< position<< endl;
        else {
            cout << "the element to remove is: "<< l.ar[position]<< endl;
            for(int i = position; i<= l.size -1; i++){
                l.ar[i] = l.ar[i+1];
                l.size --;
            }
        }

    }
}
int search(list l, string item){
    if (l.size == 0) cout<<"List is empty \n";
    else {
        for (int i = 0; i< l.size ; i ++){
            if (l.ar[i] == item) return i;
        }
    }
    return -1;
}
void traverse(list l, unsigned direction){
    if(l.size == 0) cout << "List is empty\n";
    else if (direction == DIRECTION_FORWARD) {
        for(int i = 0; i <= l.size -1; i++){
            cout<< "arr["<<i<<"]: "<< l.ar[i] << endl;
        }
    }
    else {
        for(int i = l.size -1; i>= 0; i--){
            cout<< "arr["<<i<<"]: "<< l.ar[i]<< endl;
        }
    }
}

