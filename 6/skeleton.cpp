#include <iostream>
using namespace std;

int run()
{
    __asm__(
        "movq $0, %rax"
    );

}

int main()
{
    cout << "The skeleton code for the assembly language" << endl;
    cout << "return value:" << run() << endl;
    return 0;
}