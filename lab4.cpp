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
            //loops through each node, outputs 
            while(curr != nullptr) {
                cout << curr->num << " ";
                cout << "R:" << curr->row << " C:" << curr->column << endl;
                //loop condition
                curr = curr -> right;
            }
        }

        void insert(int n, int r, int c) {
            node* newNode = new node;
            newNode -> num = n;
            newNode -> row = r;
            newNode -> column = c;
            newNode -> right = nullptr;
            newNode -> down = nullptr;

            if(isEmpty()) {
                head = newNode;
            }
            else {
                node* current = head;
                while(current -> right != nullptr) {
                    current = current -> right;
                }
                current -> right = newNode;
            }
        }
/*
        void insertDown() {
            node* current = head;
            current -> down = nullptr;
            while(current->column ) {

            }
        }
*/

};

int main(int argc, char** argv) {
    string inputFile;
    if(argc-1 == 1) {
        inputFile = argv[1];
    }

    int numRows = 0;
    int numColumns = 0;
    
    List list1;

    string line;
    ifstream file1;
    file1.open(inputFile);
    if(file1.is_open()) {
        //insert number into list 
        while(getline(file1, line)) {
            numRows++;
            istringstream iss(line);
            int num;
            numColumns = 0;
            while(iss >> num) {
                numColumns++;
                list1.insert(num, numRows, numColumns);
            }
        }
    }

    file1.close();

    //prints number of rows and columns 
    // cout << numRows << endl;
    // cout << numColumns << endl;


    list1.print();
    cout << endl;

}