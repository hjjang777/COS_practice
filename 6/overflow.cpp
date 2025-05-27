#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    int pass=0;
    char x[20];
    cout << "Enter a password: ";
    cin >> x;
    
    if (strcmp(x,"thegeekstuff")) {
        cout << "Wrong password!" << endl;
    } else {
        cout << "Correct password!" << endl;
        pass = 1;
    }

    if (pass) {
        cout << "Root privileges given to user" << endl;
    }
    cout << "x (" << (void *)x << ") = " << x << endl;
    cout << "pass (" << (void *)&pass << ") =" << pass << endl;
    return 0;
}