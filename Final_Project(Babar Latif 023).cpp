#include<iostream>
#include <cstddef>
using namespace std;

struct Node {
	int value;
	Node*next;
	Node(int val) : value(val), next(NULL) {
	}
};
class UserDataList {
 private:
 	Node* head;
 public:
 	UserDataList() : head(NULL) {
	 }
	void addUser(int val){
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}
	bool exists(int val){
		Node* current = head;
		while (current){
			if (current->value ==val) return true;
			current = current->next; 
		}
		return false;
	}
	int getFirst(){
		return head ? head->value : 0;
	}
	void removeUser(int val){
		if(!head) return;
		if (head->value == val){
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node* current = head;
		while (current->next && current->next->value != val){
			current = current->next;
		}
		if(current->next){
			Node* temp = current->next;
			current->next= temp->next;
			delete temp;
		}
	}
	Node* getHead(){ return head;
	}
	~UserDataList(){
		while (head) {
			Node* temp = head;
		    head= head->next;
			delete temp;
		}
	}
 };
 class SudokuSolver {
private:
    int board[9][9];
    UserDataList users[9][9];
    const int SIZE = 9;
    const int EMPTY = 0;

    bool isValid(int row, int col, int num) {
        for (int c = 0; c < SIZE; c++)
            if (board[row][c] == num) return false;

        for (int r = 0; r < SIZE; r++)
            if (board[r][col] == num) return false;

        int boxRow = row - (row % 3);
        int boxCol = col - (col % 3);
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                if (board[boxRow + r][boxCol + c] == num) return false;

        return true;
    }
		void initializeUser() {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (board[row][col] == EMPTY) {
                    for (int num = 1; num <= SIZE; num++) {
                        if (isValid(row, col, num)) {
                            users[row][col].addUser(num);
                        }
                    }
                }
            }
        }
    }

		 bool findEmptyCell(int& row, int& col){
		 	int minUsers = SIZE + 1;
		 	bool found = false;
		 	
		 	for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                if (board[r][c] == EMPTY) {
                    found = true;
                    int count = 0;
                    for (int num = 1; num <= SIZE; num++) {
                        if (isValid(r, c, num)) count++;
                    }

                    if (count < minUsers) {
                        minUsers = count;
                        row = r;
                        col = c;
                    }
                }
            }
        }

        return found;
		 }
		 bool solve() {
        int row, col;
        if (!findEmptyCell(row, col)) return true;

        Node* user = users[row][col].getHead();
        while (user != NULL) {
            int num = user->value;
            if (isValid(row, col, num)) {
                board[row][col] = num;
                if (solve()) return true;
                board[row][col] = EMPTY;
            }
            user = user->next;
        }

        return false;
    }
   public:
    SudokuSolver(int initialBoard[9][9]) {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                board[i][j] = initialBoard[i][j];

        initializeUser();
    }

    bool solveSudoku() {
        return solve();
    }

    void printBoard() {
        for (int row = 0; row < SIZE; row++) {
            if (row % 3 == 0 && row != 0) cout << "------+-------+------\n";

            for (int col = 0; col < SIZE; col++) {
                if (col % 3 == 0 && col != 0) cout << "| ";
                cout << board[row][col] << " ";
            }
            cout << endl;
        }
    }
 };
 int main(){
 	int board[9][9] = {
 		{5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
	 };
	 cout << "Sudoku Solver:\n";
    SudokuSolver solver(board);

    solver.printBoard();

    cout << "\nSolving...\n\n";

    if (solver.solveSudoku()) {
        cout << "Solved Sudoku:\n";
        solver.printBoard();
    } else {
        cout << "No solution found.\n";
    }
}

 
 
 
 
 
 
 
 
 
