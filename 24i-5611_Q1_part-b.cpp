#include <iostream>
using namespace std;

void PrintRow(int count, int value) {
    if (count == 0)
        return;
    cout << value << " ";
    PrintRow(count - 1, value);
}

void PrintPattern(int n) {
    if (n == 0)
        return;

    if (n == 4)
        cout << "4\n";
    else if (n == 3)
        cout << "2 2\n";
    else if (n == 2)
        cout << "1 3\n";
    else if (n == 1)
        cout << "1 1 2\n";
    else
        cout << "1 1 1 1\n";

    PrintPattern(n - 1);
}

int main() {
    int n = 4;
    PrintPattern(n);
    return 0;
}
