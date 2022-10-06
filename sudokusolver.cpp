#include <iostream>

using namespace std;
int arr[9][9] = {};

class sudoku {
    public:
        void boardinput() {
            while (true) {
                int location1, location2, startx, starty, x, y;
                cout << "Enter the location\n1|2|3\n-+-+-\n4|5|6\n-+-+-\n7|8|9\n";
                cin >> location1;
                switch (location1) {
                case 1:
                case 2:
                case 3:
                    starty = (location1 - 1) * 3;
                    startx = 0;
                    break;

                case 4:
                case 5:
                case 6:
                    starty = (location1 - 4) * 3;
                    startx = 3;
                    break;

                case 7:
                case 8:
                case 9:
                    starty = (location1 - 7) * 3;
                    startx = 6;
                    break;
                default:
                    return;
                }

                cout << "Enter the location\n1\t2\t3\n\n4\t5\t6\n\n7\t8\t9\n";
                cin >> location2;
                switch (location2) {
                case 1:
                case 2:
                case 3:
                    y = starty + (location2 - 1);
                    x = startx;
                    break;

                case 4:
                case 5:
                case 6:
                    y = starty + (location2 - 4);
                    x = startx + 1;
                    break;

                case 7:
                case 8:
                case 9:
                    y = starty + (location2 - 7);
                    x = startx + 2;
                    break;
                default:
                    return;
                }
                cout << "\nEnter value to input\n";
                cin >> arr[x][y];
            }

        }

    void printsudoku() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl << endl;
        }
    }

    bool solvesudoku(int i, int j) {
        if (i == 9) {
            return true;
        } else if (j == 9) {
            return solvesudoku(i + 1, 0);
        } else if (arr[i][j] != 0) {
            return solvesudoku(i, j + 1);
        } else {
            for (int p = 1; p <= 9; p++) {
                if (isvalid(i, j, p) == true) {
                    arr[i][j] = p;
                    if (solvesudoku(i, j + 1) == true) {
                        return true;
                    }
                    arr[i][j] = 0;
                }
            }
            return false;
        }
    }

    bool isvalid(int x, int y, int val) {
        for (int i = 0; i < 9; i++) {
            if (arr[x][i] == val) {
                return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if (arr[i][y] == val) {
                return false;
            }
        }
        int a = (x / 3) * 3, b = (y / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (arr[a + i][b + j] == val) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    sudoku board;
    cout << " ____            _       _            ____        _                " << endl;
    cout << "/ ___| _   _  __| | ___ | | ___   _  / ___|  ___ | |_   _____ _ __ " << endl;
    cout << "\\___ \\| | | |/ _` |/ _ \\| |/ / | | | \\___ \\ / _ \\| \\ \\ / / _ \\ '__|" << endl;
    cout << " ___) | |_| | (_| | (_) |   <| |_| |  ___) | (_) | |\\ V /  __/ |   " << endl;
    cout << "|____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_| |____/ \\___/|_| \\_/ \\___|_|   " << endl << endl;
    cout << "~~By Anand Panchdhari\n\n";
    board.boardinput();
    system("cls");
    cout << "\nThe sudoku problem was\n";
    board.printsudoku();
    board.solvesudoku(0, 0);
    cout << "\n\nThe solution is\n";
    board.printsudoku();
}
