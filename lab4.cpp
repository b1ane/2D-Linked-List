#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
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
    int row;     //stores row of node
    int column;  //stores column of node
    node* right; //points to node on the right
    node* down;  //points to node below
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

        void print() {
            node* curr = head;
            //node* temp_head = head;
            //loops through each node, outputs 
            while(curr != nullptr) {
                node* temp_head = curr;
                while(temp_head != nullptr) {
                    cout << temp_head->num << " ";
                    temp_head = temp_head->right;
                }
                cout << endl;
                curr = curr -> down;
            }
        }

        void insert(int n, int r, int c) {
            node* newNode = new node;
            newNode->num = n;
            newNode->row = r;
            newNode->column = c;
            newNode->right = nullptr;
            newNode->down = nullptr;

            if (isEmpty()) {
                head = newNode;
            } else {
                node* current = head;
                while( current -> right != nullptr ) {
                    if(current->column == c) {
                        newNode -> down = current;
                    }
                    current = current -> right;
                }
                current -> right = newNode;
            }
        }


};

int main(int argc, char** argv) {
    string inputFile;
    if(argc-1 == 1) {
        inputFile = argv[1];
    }

    int numRow = 0;
    int numColumn = 0;
    
    List list1;

    string line;
    ifstream file1;
    file1.open(inputFile);
    if(file1.is_open()) {
        //insert number into list 
        while(getline(file1, line)) {
            numRow++;
            istringstream iss(line);
            int num;
            numColumn = 0;
            while(iss >> num) {
                numColumn++;
                list1.insert(num, numRow, numColumn);
            }
        }
    }

    file1.close();


    list1.print();
    cout << endl;

}