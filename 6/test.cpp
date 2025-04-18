#include <iostream>
#include <cstdlib>
using namespace std;

short test(short x, short y, short z)
{
    __asm__(
        "leaq	(%rdx, %rsi), %rax\n"
        "subq	%rdi, %rax\n"
        "cmpq	$5, %rdx\n"
        "jle	.L2\n"
        "cmpq	$2, %rsi\n"
        "jle	.L3\n"
        "movq	%rdi, %rax\n"
        "idivq	%rdx, %rax\n"
        ".L3:\n"
        "movq	%rdi, %rax\n"
        "idivq	%rsi, %rax\n"
        "ret\n"
        ".L2:\n"
        "cmpq	$3, %rdx\n"
        "jge	.L4\n"
        "movq	%rdx, %rax\n"
        "idivq	%rsi, %rax\n"
        ".L4:\n"
        "rep; ret\n"
    );

}

int main(int argc, char *argv[])
{
    short x, y, z;
    if (argc != 4) {
        cout << "error: please try again with 3 numbers" << endl;
        return 1;
    }
    x = atoi(argv[1]); y = atoi(argv[2]); z = atoi(argv[3]);
    cout << "result: " << test(x, y, z) << endl; 
    return 0;

}