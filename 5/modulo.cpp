#include <iostream>
#include <cstdlib>

using namespace std;

int mod(int a, int b)
{
    if (a>=0) 
        return a % b;
    else 
        // return (b - (-a % b)) % b;
        return a/b*b-a;
}
int main(int argc, char *argv[])
{
    int a,b,c;
    if (argc!=3){
        cout << "Plaease insert two numbers" << endl;
        return 0;
    }
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    // c=a%b;
    c=mod(a,b);
    cout << a << " mod " << b << " = " << c << endl;
    return 0;
}