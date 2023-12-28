#include <iostream>
using namespace std;

int main() {
    int a[100] = {3, 2, 1, 8, 11};
    int pos, num, i;

    cout << "Old array: ";
    for (i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }

    cout << "Enter position and number: ";
    cin >> pos >> num;

    for (i = 4; i >= pos; i--) {
        a[i + 1] = a[i];
    }

    a[pos] = num;

    cout << "New array: ";
    for (i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
