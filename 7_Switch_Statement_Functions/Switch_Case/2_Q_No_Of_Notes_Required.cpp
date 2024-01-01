#include <iostream>
using namespace std;
int main() {
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int remainingAmount = amount;

    int n100, n50, n20, n10, n1;

    switch (remainingAmount ) {
        case 0:
            n100 = 0;
            break;
        default:
            n100 = remainingAmount / 100;
            remainingAmount %= 100;
    }

    switch (remainingAmount) {
        case 0:
            n50 = 0;
            break;
        default:
            n50 = remainingAmount / 50;
            remainingAmount %= 50;
    }

    switch (remainingAmount ) {
        case 0:
            n20 = 0;
            break;
        default:
            n20 = remainingAmount / 20;
            remainingAmount %= 20;
    }

    switch (remainingAmount ) {
        case 0:
            n10 = 0;
            break;
        default:
            n10 = remainingAmount / 10;
            remainingAmount %= 10;
    }

    n1 = remainingAmount;

    cout << "Notes of 100: " << n100 << endl;
    cout << "Notes of 50: " << n50 << endl;
    cout << "Notes of 20: " << n20 << endl;
    cout << "Notes of 10: " << n10 << endl;
    cout << "Notes of 1: " << n1 << endl;

    #include <iostream>


    int input = 2;
    switch (input) {
    case 1:
        cout << "One ";
    case 2:
        cout << "Two ";
    case 3:
        cout << "Three ";
    default:
        cout << "Default ";
        break;
    }



    return 0;
}
