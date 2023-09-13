#include <iostream>
#include <string> 
#include <fstream>
using namespace std;
/*
1 -> 2 -> 3 -> NULL
|         |     |
v         v     v
4 -> 5 -> 6 -> NULL
|        |     |
v        v     v
7 -> 8 -> 9 -> NULL
|         |       |
v         v       v
NULL     NULL    NULL

*/


//node for linked list 
struct node {
    int num;
    node* right; //points to 
    node* down;
};

class List {
    private:
        node* head;
    public:
        //Constructor
        List() {
            //initialize List
            head = nullptr;
        }

        //Checks if List is empty
        bool isEmpty() {
            return head == nullptr;
        }

        void insertAtEnd(int x) {
            //new node created
            node* newNode = new node;
            //node holds value being passed in parameter
            newNode -> num = x;
            //next node is set to null
            newNode -> right = nullptr;
            newNode -> down = nullptr;

            //if list is empty - set element as head node
            if(isEmpty()) {
                head = newNode;
            }
            else {
                //current node set to save value of head
                node* curr = head;

                //loop until last node is reached, node afterwards will always be empty 
                while(curr->right != nullptr) {
                    curr = curr->right;
                }
                //set last node's next pointer to point at new node created 
                curr->right = newNode;
                }  
        }

        void print() {
            node* curr = head;

            //loops through each node, outputs 
            while(curr != nullptr) {
                cout << curr->num << endl;
                //loop condition
                curr = curr -> right;
            }
        }

};

int main(int argc, char** argv) {
    string inputFile;
    if(argc-1 == 1) {
        inputFile = argv[1];
    }

    List list1;
    int num;
    ifstream file1;
    file1.open(inputFile);
    if(file1.is_open()) {
        while(file1 >> num) {
            list1.insertAtEnd(num);
        }
    }

    list1.print();
    
    

    


}