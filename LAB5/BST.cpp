#include<iostream>
#include <queue>

using namespace std;

int ks[] = {1,8,3,2,10};


struct node{
    int key;
    node* left, *right;
};

void inorderHelper(node* root);
void preorderHelper(node *root);
void postorderHelper(node *root);
void levelOrderHelper(node* root);
node* deleteNode(node* root, int key);


class BST {
    private:
        node* r; //root
    public: 
        BST();
        ~BST();
        void insert(const int& key);
        void remove(const int& key);
        void create(int keys[], int size);
        void inorder() const;
        void postorder() const;
        void preorder() const;
        void levelOrder() const;
        bool search(const int& key) const;
};

int main(int argc, char const *argv[])
{
    char user_option;
    int temp_int;
    BST tree;

    cout<<"BST Pointer implementation.\n";
    while (user_option != 'q')
    {
        cout << "> Please select an option to proceed: \n"
             << "    i: insert new element\n"
             << "    r: remove element \n"
             << "    c: create tree from an array \n"
             << "    d: display tree elements. \n"
             << "    s: search element \n"
             << "    q: to quit the program \n";
        cin >> user_option;

        switch (user_option)
        {
        case 'i': /*insert*/
            cout << "> type the value to be inserted: ";
            cin >> temp_int;
            tree.insert(temp_int);
            break;

        case 'r': /*remove*/
            cout << "> type the key of the element: ";
            cin >> temp_int;
            tree.remove(temp_int);
            break;


        case 'c': /*create*/
            cout<<"creating tree for the provided array...";
            tree.create(ks, 5);
            break;
            
        case 'd': /*display*/
            cout<<"> choose in which order: \n";
            cout<<"   1-level order\n   2-inorder\n   3-postorder\n   4-preorder: ";
            cin >> temp_int;

            switch (temp_int)
            {
            case 1:
                tree.levelOrder();
                break;
            case 2:
                tree.inorder();
                break;
            case 3:
                tree.postorder();
                break;   
            case 4:
                tree.preorder();
                break;                             
            default:
                cout<<"Wrong input!\n";
                break;
            }
            break;

        case 's': /*search*/
            cout<<"> search for key: ";
            cin >> temp_int;
            if(tree.search(temp_int)) cout<<"key found";
            else cout<<"key not found";
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
BST::BST(){
    r = nullptr;
}
BST::~BST(){}

void BST::insert(const int& key){
        node* newNode = new node;
        newNode->key = key;
        if (r == NULL) {
            r = newNode;
            return;
        }
        node* curr = r;
        while (true) {
            if (key < curr->key) {
                if (curr->left == NULL) {
                    curr->left = newNode;
                    break;
                }
                else {
                    curr = curr->left;
                }
            }
            else {
                if (curr->right == NULL) {
                    curr->right = newNode;
                    break;
                }
                else {
                    curr = curr->right;
                }
            }
        }
}
void BST::remove(const int& key){
    node* nodeRemove = deleteNode(r, key);
    cout<<"Node to be removed: "<< key <<endl;
}
void BST::create(int keys[], int size){
    for(int i = 0; i< size; i++){
        BST::insert(keys[i]);
    }
}
void BST::inorder() const{
    inorderHelper(r);
}
void BST::preorder() const{
    preorderHelper(r);
}
void BST::postorder() const{
    postorderHelper(r);
}
void BST::levelOrder() const{
    levelOrderHelper(r);
}
bool BST::search(const int& key) const{
    node* curr = r;
        while (curr != NULL) {
            if (key == curr->key) {
                return true;
            }
            else if (key < curr->key) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
        return false;
}


//Helper Functoin.
void inorderHelper(node* root){
    if(root != NULL){
        inorderHelper(root->left); 
        printf("%d",root->key); 
        inorderHelper(root->right);
    } 

}
void preorderHelper(node *root){
    if(root != NULL){
        printf("%d",root->key); 
        preorderHelper(root->left); 
        preorderHelper(root->right);
    } 

}
void postorderHelper(node *root){
    if(root != NULL){
        postorderHelper(root->left); 
        postorderHelper(root->right);
        printf("%d",root->key); 
    } 

}
void levelOrderHelper(node* root){
    if (root == NULL) {
        cout<<"Error: root not found\n";
        return;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
       root = q.front();
        cout << root->key << " ";
        q.pop();
        if (root->left != NULL) {
            q.push(root->left);
        }
        if (root->right != NULL) {
            q.push(root->right);
        }
    }
}
node* deleteNode(node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
