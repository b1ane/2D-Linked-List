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
            node* currentRow = head;
            //loop through rows 
            while(currentRow != nullptr) {
                //keep track of row 
                node* currentColumn = currentRow;
                while(currentColumn != nullptr) {
                    cout << currentColumn->num << " ";
                    currentColumn = currentColumn->right;
                }
                cout << endl;
                currentRow = currentRow -> down;
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
                node* currentRow = head;
                node* prevRow = nullptr;

                //Checks if current row is equal to row number in matrix is at 
                //Loop untile correct row is found 
                while (currentRow != nullptr && currentRow->row < r) {
                    //keeps track of the row before
                    prevRow = currentRow;
                    //loop condition 
                    currentRow = currentRow->down;
                }

                node* currentColumn = currentRow;
                node* prevColumn = nullptr;

                // Checks if current column is equal to column number in matrix
                //Loops until correct column is found
                while (currentColumn != nullptr && currentColumn->column < c) {
                    prevColumn = currentColumn;
                    //loop condition
                    currentColumn = currentColumn->right;
                }

                //Check if node in row alread has same column number
                if (currentColumn != nullptr && currentColumn->column == c) {
                    //Insert after that node 
                    newNode->right = currentColumn->right;
                    currentColumn->right = newNode;
                } else {
                    // Node with the same column does not exist, insert in the column
                    if (prevColumn != nullptr) {
                        newNode->right = prevColumn->right;
                        prevColumn->right = newNode;
                    } else {
                        newNode->right = currentRow;
                        if (prevRow != nullptr) {
                            prevRow->down = newNode;
                        } else {
                            head = newNode;
                        }
                    }
                }

                // Connect nodes below in the same column
                if (currentRow != nullptr && currentRow != newNode) {
                    newNode->down = currentRow;
                }
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
    int row = 0;
    
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
            int column = 0;
            while(iss >> num) {
                numColumn++;
                list1.insert(num, numRow, numColumn);
                column++;
            }
            row++;
        }
    }

    file1.close();


    list1.print();
    cout << endl;

}