#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int Task1(int K, int L, int* arr);
string* Task2(int K, int L, int* arr, int G);
int Task3(int K, int L, int* arr, int G, int fnd);
int* Task4(int K, int L, int* arr, int G);
int* Task5(int K, int L, int* arr, int G, int first, int second, int ind1, int ind2);

int main() {
    int K;
    int G;
    int* arr;
    int length;
    char variable;
    int L;
    int fnd;
    int first, second;

    cout << "Input length of your surname" << endl;
    cin >> K;

    cout << "Input number of vowels in your name" << endl;
    cin >> G;

    cout << "What do you want to do?" << endl;
    cout << "1. The smallest or the biggest number in the array" << endl;
    cout << "2. Output of all values of array elements and display of histogram according to their values using a symbol" << endl;
    cout << "3. Search for the value of the array element specified by the user using the algorithm" << endl;
    cout << "4. Derivation of indices of array elements" << endl;
    cout << "5. Array sorting" << endl;
    cin >> variable;

    switch (variable) {
    case '1': {
        L = K * 4;
        length = K;
        arr = new int[length];

        for (int i = 0; i < length; i++) {
            arr[i] = rand() % L;
            cout << arr[i] << " / ";
        }

        int re = Task1(K, L, arr);

        cout << "The smallest or the biggest number in the array is " << re << endl;

        break;
    }
    case '2': {
        L = K * 4;
        length = K;
        arr = new int[length];

        for (int i = 0; i < length; i++) {
            arr[i] = rand() % L;
            cout << arr[i] << " / ";
        }
        cout << endl;
        string* arr2 = Task2(K, L, arr, G);
        for (int i = 0; i < K; i++) {
            cout << arr[i] << " = " << arr2[i] << endl;
        }
        delete[] arr2;
        break;
    }
    case '3': {
        L = K * 4;
        length = K;
        arr = new int[length];

        for (int i = 0; i < length; i++) {
            arr[i] = rand() % L;
            cout << arr[i] << " / ";
        }
        cout << endl;
        cout << "Which element do you want to find" << endl;
        cin >> fnd;
        int nmbr = Task3(K, L, arr, G, fnd);
        cout << "Your number = " << fnd << " is in " << nmbr << " position in array = arr[ " << nmbr << " ]" << endl;
        break;
    }
    case '4': {
        L = K * 4;
        length = K;
        arr = new int[length];

        for (int i = 0; i < length; i++) {
            arr[i] = rand() % L;
            cout << arr[i] << " / ";
        }
        cout << endl;
        int* arr2 = Task4(K, L, arr, G);

        cout << "Biggest or smallest element(s) found at index/indices: ";

        for (int i = 0; i < K; i++) {
            cout << arr2[i] << " / ";
        }
        cout << endl;
        int zero = 0;
        for (int i = 0; i < G; i++) {
            cout << zero++ << " ";
        }
        break;
    }
    case '5': {
        L = K * 4;
        length = K;
        arr = new int[length];
        int ind1, ind2;

        for (int i = 0; i < length; i++) {
            arr[i] = rand() % L;
            cout << arr[i] << " / ";
        }
        cout << "How do you want to sort your array?" << endl << "1. Increasing   2. Decreasing" << endl;
        cin >> first;
        cout << "What part of array do you want to sort?" << endl << "1. All of array" << endl << "2. Sort that part of the array whose elements are between the minimum max value of the array before sorting" << endl << "3. Sort the array in the part between the given sequence numbers by the user" << endl;
        cin >> second;
        if (second == 3) {
            cout << "Input first number" << endl;
            cin >> ind1;
            cout << "Input second number" << endl;
            cin >> ind2;
        }

        int* arr1 = Task5(K, L, arr, G, first, second, ind1, ind2);
        for (int i = 0; i < K; i++) {
            cout << arr1[i] << " / ";
        }
        break;
    }
    default:
        cout << "Invalid option";
    }
    return 0;
}

int Task1(int K, int L, int* arr) {
    int length = K;

    if (K % 2 == 0) {
        int max = arr[0];
        for (int i = 1; i < length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        int re = max;
        return re;
    }
    else {
        int min = arr[0];
        for (int i = 1; i < length; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        int re = min;
        return re;
    }

}

string* Task2(int K, int L, int* arr, int G) {
    string* arr2 = new string[K];
    char symbol;

    if (G % 2 == 0) {
        symbol = '+';
    }
    else {
        symbol = '|';
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < arr[i]; j++) {
            arr2[i] += symbol;
        }
    }

    return arr2;
}
int Task3(int K, int L, int* arr, int G, int fnd) {
    int nmbr = -1;
    if (G % 2 == 0) {
        for (int i = 0; i < K; i++) {
            if (arr[i] == fnd) {
                nmbr = i;
                break;
            }
        }
    }
    else {
        int left = 0, right = K - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == fnd) {
                nmbr = mid;
                break;
            }
            else if (arr[mid] > fnd) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
    }
    return nmbr;
}
int* Task4(int K, int L, int* arr, int G) {
    int temp;
    if (K % 2 == 0) {
        for (int i = 0; i < K; i++) {
            for (int j = i + 1; j < K; j++) {
                if (arr[i] < arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    else {
        for (int i = 0; i < K; i++) {
            for (int j = i + 1; j < K; j++) {
                if (arr[i] > arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    return arr;

}
int* Task5(int K, int L, int* arr, int G, int first, int second, int ind1, int ind2) {
    bool swapped;
    int i, j, minIndex, maxIndex, tmp;
    //1
    if ((K % 2 == 0 || G % 2 == 0) && (first == 1)) {
        if (second == 1) {
            for (int i = 0; i < K - 1; i++) {
                swapped = false;
                for (int j = 0; j < K - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }
                }
                if (swapped == false) {
                    break;
                }
            }
        }
        else if (second == 2) {
            int min_idx = 0, max_idx = 0;
            for (int i = 1; i < K; i++) {
                if (arr[i] < arr[min_idx]) {
                    min_idx = i;
                }
                else if (arr[i] > arr[max_idx]) {
                    max_idx = i;
                }
            }
            if (max_idx < min_idx) {
                swap(min_idx, max_idx);
            }

            for (int i = min_idx + 1; i < max_idx; i++) {
                for (int j = min_idx + 1; j < max_idx; j++) {
                    if (arr[j - 1] > arr[j]) {
                        swap(arr[j - 1], arr[j]);
                    }
                }
            }
        }
        else if (second == 3) {
            int temp;
            for (i = ind1; i <= ind2; i++) {
                for (j = ind1; j <= ind2 - i + ind1 - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
    }
    else if ((K % 2 == 0 || G % 2 == 0) && (first == 2)) {
        if (second == 1) {
            for (int i = 0; i < K - 1; i++) {
                swapped = false;
                for (int j = 0; j < K - i - 1; j++) {
                    if (arr[j] < arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }
                }
                if (swapped == false) {
                    break;
                }
            }
        }
        else if (second == 2) {
            int min_idx = 0, max_idx = 0;
            for (int i = 1; i < K; i++) {
                if (arr[i] < arr[min_idx]) {
                    min_idx = i;
                }
                else if (arr[i] > arr[max_idx]) {
                    max_idx = i;
                }
            }
            if (max_idx < min_idx) {
                swap(min_idx, max_idx);
            }

            for (int i = min_idx + 1; i < max_idx; i++) {
                for (int j = min_idx + 1; j < max_idx; j++) {
                    if (arr[j - 1] < arr[j]) {
                        swap(arr[j - 1], arr[j]);
                    }
                }
            }
        }
        else if (second == 3) {
            int temp;
            for (i = ind1; i <= ind2; i++) {
                for (j = ind1; j <= ind2 - i + ind1 - 1; j++) {
                    if (arr[j] < arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
    }
    //2
    else if ((K % 2 == 0 || G % 2 != 0) && (first == 1)) {
        if (second == 1) {
            for (i = 0; i < K - 1; i++) {
                minIndex = i;
                for (j = i + 1; j < K; j++)
                    if (arr[j] < arr[minIndex])
                        minIndex = j;
                if (minIndex != i) {
                    tmp = arr[i];
                    arr[i] = arr[minIndex];
                    arr[minIndex] = tmp;
                }
            }
        }
        else if (second == 2) {
            int min_idx = 0, max_idx = 0;
            for (int i = 1; i < K; i++) {
                if (arr[i] < arr[min_idx]) {
                    min_idx = i;
                }
                else if (arr[i] > arr[max_idx]) {
                    max_idx = i;
                }
            }
            if (max_idx < min_idx) {
                swap(min_idx, max_idx);
            }

            for (int i = min_idx + 1; i < max_idx; i++) {
                int min_elem = i;
                for (int j = i + 1; j < max_idx; j++) {
                    if (arr[j] < arr[min_elem]) {
                        min_elem = j;
                    }
                }
                swap(arr[i], arr[min_elem]);
            }
        }
        else if (second == 3) {

            for (i = ind1; i < ind2; i++) {

                minIndex = i;
                for (j = i + 1; j <= ind2; j++) {
                    if (arr[j] < arr[minIndex]) {
                        minIndex = j;
                    }
                }

                int temp = arr[minIndex];
                arr[minIndex] = arr[i];
                arr[i] = temp;
            }
        }
    }
    else if ((K % 2 == 0 || G % 2 != 0) && (first == 2)) {
        if (second == 1) {
            for (i = 0; i < K - 1; i++) {
                maxIndex = i;
                for (j = i + 1; j < K; j++)
                    if (arr[j] > arr[maxIndex])
                        maxIndex = j;
                if (maxIndex != i) {
                    tmp = arr[i];
                    arr[i] = arr[maxIndex];
                    arr[maxIndex] = tmp;
                }
            }
        }
        else if (second == 2) {
            int min_idx = 0, max_idx = 0;
            for (int i = 1; i < K; i++) {
                if (arr[i] < arr[min_idx]) {
                    min_idx = i;
                }
                else if (arr[i] > arr[max_idx]) {
                    max_idx = i;
                }
            }
            if (max_idx < min_idx) {
                swap(min_idx, max_idx);
            }

            for (int i = min_idx + 1; i < max_idx; i++) {
                int min_elem = i;
                for (int j = i + 1; j < max_idx; j++) {
                    if (arr[j] > arr[min_elem]) {
                        min_elem = j;
                    }
                }
                swap(arr[i], arr[min_elem]);
            }
        }
        else if (second == 3) {
            for (i = ind1; i < ind2; i++) {
                maxIndex = i;
                for (j = i + 1; j <= ind2; j++) {
                    if (arr[j] > arr[maxIndex]) {
                        maxIndex = j;
                    }
                }

                int temp = arr[maxIndex];
                arr[maxIndex] = arr[i];
                arr[i] = temp;
            }
        }
    }
    //3
    else if ((K % 2 != 0 || G % 2 == 0) && (first == 1)) {
        if (second == 1) {
            int i, j, key;
            for (i = 1; i < K; i++) {
                key = arr[i];
                j = i - 1;
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
        }
        else if (second == 2) {
            int min_idx = 0, max_idx = 0;
            for (int i = 1; i < K; i++) {
                if (arr[i] < arr[min_idx]) {
                    min_idx = i;
                }
                else if (arr[i] > arr[max_idx]) {
                    max_idx = i;
                }
            }
            if (max_idx < min_idx) {
                swap(min_idx, max_idx);
            }

            for (int i = min_idx + 1; i <= max_idx; i++) {
                int key = arr[i];
                int j = i - 1;
                while (j >= min_idx && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
        }
        else if (second == 3) {
            int i, j, key;
            for (i = ind1 + 1; i <= ind2; i++) {
                key = arr[i];
                j = i - 1;

                while (j >= ind1 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }

                arr[j + 1] = key;
            }
        }
    }
    else if ((K % 2 != 0 || G % 2 == 0) && (first == 2)) {
        if (second == 1) {
            int i, j, key;
            for (i = 1; i > K; i++) {
                key = arr[i];
                j = i - 1;
                while (j <= 0 && arr[j] < key) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
        }
        else if (second == 2) {
            int min_idx = 0, max_idx = 0;
            for (int i = 1; i < K; i++) {
                if (arr[i] < arr[min_idx]) {
                    min_idx = i;
                }
                else if (arr[i] > arr[max_idx]) {
                    max_idx = i;
                }
            }
            if (max_idx < min_idx) {
                swap(min_idx, max_idx);
            }

            for (int i = min_idx + 1; i <= max_idx; i++) {
                int key = arr[i];
                int j = i - 1;
                while (j <= min_idx && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }

        }
        else if (second == 3) {
            int i, j, key;
            for (i = ind1 + 1; i <= ind2; i++) {
                key = arr[i];
                j = i - 1;

                while (j <= ind1 && arr[j] < key) {
                    arr[j + 1] = arr[j];
                    j--;
                }

                arr[j + 1] = key;
            }
        }
    }
    //4
    else if ((K % 2 != 0 || G % 2 != 0) && (first == 1)) {
        if (second == 1) {
            bool swapped;
            for (int i = 0; i < K - 1; i++) {
                swapped = false;
                for (int j = 0; j < K - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }
                }
                if (swapped == false) {
                    break;
                }
            }
        }
        else if (second == 2) {
            int min_idx = 0, max_idx = 0;
            for (int i = 1; i < K; i++) {
                if (arr[i] < arr[min_idx]) {
                    min_idx = i;
                }
                else if (arr[i] > arr[max_idx]) {
                    max_idx = i;
                }
            }
            if (max_idx < min_idx) {
                swap(min_idx, max_idx);
            }

            for (int i = min_idx + 1; i < max_idx; i++) {
                for (int j = min_idx + 1; j < max_idx; j++) {
                    if (arr[j - 1] > arr[j]) {
                        swap(arr[j - 1], arr[j]);
                    }
                }
            }
        }
        else if (second == 3) {
            int temp;
            for (i = ind1; i <= ind2; i++) {
                for (j = ind1; j <= ind2 - i + ind1 - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
    }
    else if ((K % 2 != 0 || G % 2 != 0) && (first == 2)) {
        if (second == 1) {
            bool swapped;
            for (int i = 0; i < K - 1; i++) {
                swapped = false;
                for (int j = 0; j < K - i - 1; j++) {
                    if (arr[j] < arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                        swapped = true;
                    }
                }
                if (swapped == false) {
                    break;
                }
            }
        }
        else if (second == 2) {
            int min_idx = 0, max_idx = 0;
            for (int i = 1; i < K; i++) {
                if (arr[i] < arr[min_idx]) {
                    min_idx = i;
                }
                else if (arr[i] > arr[max_idx]) {
                    max_idx = i;
                }
            }
            if (max_idx < min_idx) {
                swap(min_idx, max_idx);
            }

            for (int i = min_idx + 1; i < max_idx; i++) {
                for (int j = min_idx + 1; j < max_idx; j++) {
                    if (arr[j - 1] < arr[j]) {
                        swap(arr[j - 1], arr[j]);
                    }
                }
            }
        }
        else if (second == 3) {
            int temp;
            for (i = ind1; i <= ind2; i++) {
                for (j = ind1; j <= ind2 - i + ind1 - 1; j++) {
                    if (arr[j] < arr[j + 1]) {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        }
    }
    return arr;
}