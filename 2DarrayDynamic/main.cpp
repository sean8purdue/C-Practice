#include <iostream>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

//    int size;
//    int ar[10] = {0};
//
//    cin >> size;
//    int *arA = NULL;
//    arA = new int(size);
//
//
//    for (int i = 0; i < size; i++) {
//        arA[i] = i;
//
//    }
//
//    for (int i = 0; i < size; i++) {
//        cout << ar[i] ;
//        cout << arA[i];
//
//    }
//
//    delete [] ar;
//    arA = NULL;

    // 2d double array dynamic allocation

    int row;
    int col;

//    cin >> row >> col;
    row = 3;
    col = 5;

    // dynamic allocate 2D array
    double ** arD = new double*[row];
    for (int i = 0; i < row; i++)
        arD[i] = new double[col];

    // fill 2D array
    for(int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            arD[i][j] = 1.2 + i;

    // print the 2D array like table
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << arD[i][j] << " ";

        cout << endl;
    }


//    cout << *arD;
    // free
    for (int i = 0; i < row; i++)
        delete [] arD[i];
    delete[] arD;
    cout << *arD << endl;
    arD = NULL;

    // after set arD to NULL, cout << *arD will cause error
//    cout << *arD;

    // arD itself is stored in Stack, will invalid after main exit
    cout << &arD;

    return 0;
}