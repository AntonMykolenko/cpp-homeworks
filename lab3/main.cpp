#include <iostream>
#include <math.h>

using namespace std;

void sravnenie(char *str, int n)
{
    int size, y;
    string stroka1 = str;
    string stroka2;
    cout << "Enter comparison string : ";
    cin >> stroka2;

    size = stroka2.size();
    y = stroka1.size();
    cout << endl << "Initial string length: " << y << endl;
    cout << "Comparison string length: " << size << endl;

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<y; j++)
        {
            if(stroka2[i] == *(str + j))
            {
                *(str + j) = '#';
                break;
            }
        }
    }

    int c = 0;
    for(int i=0; i<y; i++)
    {
        if(stroka1[i] == stroka2[i])
        {
            c++;
        }
    }
    if(c == size)
    {
        cout << "The initial row has all elements of the comparative." << endl;
    }
    else
    {
        cout << "The initial string does not have all the elements of the comparison." << endl;
    }
    cout << "Initial string after replacement of identical characters: {";
    for(int i=0; i<y; i++)
    {
        cout << *(str + i) << " ";
    }
    cout << "}";
}
void fillingByHand(char *str)
{
    cout << "Input String: ";
    cin.ignore();
    cin.getline(str, 100);
}
char fillingRandom(char *str, int n)
{
    cout << "Choose string size: ";
    cin >> n;
    while (n < 1)
    {
        cout << "Size of your string is unavailable. Try again: " << endl;
        cin >> n;
    }
    cout << endl;

    int v, q;
    cout << "You have a choice of the type of filling elements: " << endl;
    cout << "1. Only digits" << endl << "2. Only letters" << endl << "3. All symbols" << endl;
    cout << "Your choice: ";
    cin >> v;
    while (v < 1 or v > 3)
    {
        cout << "There is no such choice. Try again: " << endl;
        cin >> v;
    }
    cout << endl;

    srand(time(NULL));
    char strokaNum[] = "1234567890";
    char strokaLet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char strokaKomb[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    switch (v)
    {
        case 1:
        {
            cout << "String: { ";
            for(int i=0; i<n; i++)
            {
                q = rand() % 10;
                str[i] = strokaNum[q];
                cout << str[i] << " ";
            }
            cout << "}";
            break;
        }
        case 2:
        {
            cout << "String: { ";
            for(int i=0; i<n; i++)
            {
                q = rand() % 52;
                str[i] = strokaLet[q];
                cout << str[i] << " ";
            }
            cout << "}";
            break;
        }
        case 3:
        {
            cout << "String: { ";
            for(int i=0; i<n; i++)
            {
                q = rand() % 62;
                str[i] = strokaKomb[q];
                cout << str[i] << " ";
            }
            cout << "}";
            break;
        }
    }
    cout << endl;
    return *str;
}
char stroka()
{
    int n;
    char *str;
    char stroka[n];
    str = &stroka[n];

    int choice;
    cout << "Choose how you want to fill your string: " << endl;
    cout << "1. Random" << endl << "2. Manually" << endl;
    cin >> choice;

    while (choice < 1 or choice > 3)
    {
        cout << "There is no such choice. Try again: " << endl;
        cin >> choice;
    }
    cout << "Your choice: " << choice << endl << endl;

    switch (choice)
    {
        case 1:
        {
            fillingRandom(str, n);
            break;
        }
        case 2:
        {
            fillingByHand(str);
            break;
        }
    }
    sravnenie(str, n);
}
int main()
{
    stroka();
}