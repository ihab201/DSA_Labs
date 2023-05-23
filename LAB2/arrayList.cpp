#include <iostream>
using namespace std;

const int maxsize = 10;

struct list {
    int length;
    string arr[maxsize];
};

void forward(list& arrlist) {
    for (int i = 0; i < arrlist.length; i++) {
        cout << arrlist.arr[i] << endl;
    }
}

void backward(list& arrlist) {
    for (int i = arrlist.length - 1; i >= 0; i--) {
        cout << arrlist.arr[i] << endl;
    }
}

void init(list& l) {
    l.length = 0;
}

void insert(list& arrlist, string name, unsigned p) {
    if (arrlist.length == maxsize) {
        cout << "List is full" << endl;
        return;
    }
    if (p > maxsize) {
        cout << "No such position" << endl;
        return;
    }
    for (int i = arrlist.length - 1; i >= p; i--) {
        arrlist.arr[i + 1] = arrlist.arr[i];
    }
    arrlist.arr[p] = name;
    arrlist.length++;
}

int search(list& arrlist, string name) {
    for (int i = 0; i < arrlist.length; i++) {
        if (arrlist.arr[i] == name) {
            return i;
        }
    }
    return -1;
}

void remove(list& arrlist, unsigned p) {
    if (p >= arrlist.length) {
        cout << "No such position" << endl;
        return;
    }
    for (int i = p; i < arrlist.length - 1; i++) {
        arrlist.arr[i] = arrlist.arr[i + 1];
    }
    arrlist.length--;
}

int main() {
    list arrlist;
    init(arrlist);
    int selection;
    string nameSelected;
    int p;

    cout << "Your list is empty! Please insert the first name to start:" << endl;
    cin >> arrlist.arr[0];
    arrlist.length = 1;

    while (true) {
        cout << "Please choose an operation by inserting the corresponding number:" << endl;
        cout << "1. Insert a name" << endl;
        cout << "2. Delete a name" << endl;
        cout << "3. Search a name" << endl;
        cout << "4. Traverse forward" << endl;
        cout << "5. Traverse backward" << endl;
        cout << "Enter Q if you want to quit" << endl;

        cin >> selection;

        if (selection == 1) {
            cout << "Please enter the name and the position where you want to perform an insertion:" << endl;
            cin >> nameSelected;
            cin >> p;
            insert(arrlist, nameSelected, p);
        } else if (selection == 2) {
            cout << "Please enter the position of the name that you want to delete:" << endl;
            cin >> p;
            remove(arrlist, p);
        } else if (selection == 3) {
            cout << "Please enter the name that you want to find:" << endl;
            cin >> nameSelected;
            int index = search(arrlist, nameSelected);
            if (index == -1) {
                cout << "Name not found" << endl;
            } else {
                cout << "Name found at position " << index << endl;
            }
        } else if (selection == 4) {
            forward(arrlist);
        } else if (selection == 5){
            backward(arrlist);
        } else return 0 ;
    }
}