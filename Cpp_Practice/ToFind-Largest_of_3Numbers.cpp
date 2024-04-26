#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    char q;

    do {
        cout << "Enter 3 numbers:\t";
        cin >> a >> b >> c;

        if (a > b && a > c)
            cout << "Largest Num: " << a;
        else if (b > a && b > c)
            cout << "Largest Num: " << b;
        else
            cout << "Largest Num: " << c;

        cout << "\nContinue? (Y/N): ";
        cin >> q;

    } while (q == 'Y' || q == 'y');

    return 0;
}
