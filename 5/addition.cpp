#include <iostream>
#include <cstring>

using namespace std;

int uadd_ok(unsigned int a, unsigned int b) {
    int max = 0xFFFFFFFF;
    int diff = max - a;

    return diff>b   ;
}

int tadd_ok(int a, int b) {
    int int_max = 0x7FFFFFFF;
    int t, overflow; 
    overflow=(a>0 && b>0 && t<0) || (a<0 && b<0 && t>0);
    if (overflow==1)
        return 0;
    else
        return 1;
    // if ((a > 0) && (b > 0) && (a > int_max - b)) {
    //     return 0;
    // }
    // else
    //     return 1;
}

int main(int argc, char *argv[])
{
    int a,b;
    unsigned int x, y;

    if (argc != 3) {
        cout << "You should insert two numbers in a hexadecimal way" << endl;
        return 1;
    }

    a=strtol(argv[1], NULL, 16);
    b=strtol(argv[2], NULL, 16);
    x=(unsigned int)a;
    y=(unsigned int)b;
    cout << "Unsigned Addition ===" << endl;

    if (uadd_ok(x, y)) {
        cout << "No overflow" << endl;
    } else {
        cout << "Overflow" << endl;
    }
    cout << "Signed Addition ===" << endl;
    if (tadd_ok(a, b)) {
        cout << "No overflow" << endl;
    } else {
        cout << "Overflow" << endl;
    }

    return 0;
}