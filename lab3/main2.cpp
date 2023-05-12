#include <iostream>
#include <random>

using namespace std;

void arrayFilling(int K, int G, int n, int n2, int** arr);
int findBiggest1(int n, int n2, int** arr);
int findBiggest2(int n, int n2, int** arr);
int findBiggest3(int n, int n2, int** arr);

int main () {
    int K, G;
    int n;
    int n2;
    cout << "Input K: " << endl;
    cin >> K;
    cout << "Input G: " << endl;
    cin >> G;
    cout << "Input n: " << endl;
    cin >> n;

    n2 = n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n2];
    }

    arrayFilling(K, G, n, n2, arr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    if (G % 2 == 0){
        int biggest = findBiggest1(n, n2, arr);
        cout << "The biggest number in the lower-right half of the array is: " << biggest << endl;
        int biggest2 = findBiggest2(n, n2, arr);
        cout << "The biggest number in the upper triangular quarter of the array is: " << biggest2 << endl;
    }
    else if (G % 2 != 0){
        int biggest = findBiggest1(n, n2, arr);
        cout << "The biggest number in the lower-right half of the array is: " << biggest << endl;
        int biggest2 = findBiggest3(n, n2, arr);
        cout << "The biggest number in all  of the array except for the left triangular quarter: " << biggest2 << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

void arrayFilling(int K, int G, int n, int n2, int** arr) {
    int range = K + 15 - (K + 3) + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n2; j++) {
            arr[i][j] = rand() % range + (-(K + 3));
        }
    }
}

int findBiggest1(int n, int n2, int** arr) {
    int biggest = arr[n/2][n2/2];
    for (int i = n/2; i < n; i++) {
        for (int j = n2/2; j < n2; j++) {
            if (arr[i][j] > biggest) {
                biggest = arr[i][j];
            }
        }
    }
    return biggest;
}

int findBiggest2(int n, int n2, int** arr) {
    int biggest = arr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n2; j++) {
            if (arr[i][j] > biggest) {
                biggest = arr[i][j];
            }
        }
    }
    return biggest;
}

int findBiggest3(int n, int n2, int** arr){
    int biggest = arr[0][n-1];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n2; j++) {
            if (i > j && arr[i][j] > biggest) {
                biggest = arr[i][j];
            }
        }
    }

    return biggest;
}