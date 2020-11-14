#include<iostream>
using namespace std;

#define MAX 8
int A[MAX][MAX] = {-1};
int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2 };
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1 };
int sizeOfBoard;
void initMap(int size_) {
    for (int i = 0; i < sizeOfBoard; ++i)
    {
        for (int j = 0; j < sizeOfBoard; ++j)
            A[i][j] = -1;;
    }
}
void output() {
    {
        for (int j = 0; j < sizeOfBoard; ++j)
       
        {
            for (int i = 0; i < sizeOfBoard; ++i)
                cout << A[i][j] << "   ";;
            cout << endl;
        }
        cout << endl;
    }
}
bool checkCondition(int x, int y, int A[MAX][MAX]) {
    if (x >= 0 && x < sizeOfBoard && y >= 0
        && y < sizeOfBoard && A[x][y] == -1)
        return true;
    return false;
}
bool move(int x_, int y_, int numOFSteps_) {
    if (numOFSteps_ == sizeOfBoard * sizeOfBoard)
        return true;
    for (int i = 0; i < 8; i++) {
        int xNext = x_ + X[i];
        int yNext = y_ + Y[i];
        if (checkCondition(xNext, yNext, A)) {
            A[xNext][yNext] = numOFSteps_;
            if(move(xNext, yNext, numOFSteps_+1))
                return true;
            else A[xNext][yNext] = -1;
        }
    }
    return false;
}
void KNtour(int x, int y) {
    A[x][y] = 0;
    if (move(x, y, 1))
        output();
    else 
        cout << "No solution - __ - ";
}
int main() {
    output();
    cout << "Size of board: ";
    cin >> sizeOfBoard;
    initMap(sizeOfBoard);
    int x_, y_;
    cout << "you start at?.\nx: ";
    cin >> x_;
    cout << "y: ";
    cin >> y_;
    KNtour(x_, y_);
}
