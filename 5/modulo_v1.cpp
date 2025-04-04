#include <iostream>
#include <cstdlib>

using namespace std;
int mod(int a, int b);
int slen(char *snum);
int convert(char *snum);

int main(int argc, char *argv[])
{
    int a,b,c;
    if (argc!=3){
        cout << "Plaease insert two numbers" << endl;
        return 0;
    }
    // a=atoi(argv[1]);
    a=convert(argv[1]);
    // b=atoi(argv[2]);
    b=convert(argv[2]);
    // c=a%b;
    c=mod(a,b);
    cout << a << " mod " << b << " = " << c << endl;
    return 0;
}

int mod(int a, int b)
{
    if (a>=0) 
        return a % b;
    else 
        // return (b - (-a % b)) % b;
        return a/b*b-a;
}

int slen(char *snum)
{
    // int len=0;
    // while (snum[len]!='\0')
    //     len++;
    // return len;

    int ret;
    char *p;
    ret=0;

    p=snum;
while (*p!='\0')
    {
        ret++;
        p++;
    }
    return ret;
}

int convert(char *snum)
{
    // int len = strlen(snum);
    int len=slen(snum);
    int i, ret;
    int sign;
    char *p;
    ret=0;
    p=snum;
    sign=1;

    if (*p=='-')
    {
        sign=-1;
        p++;
    }

    len=slen(p);
    
    for (i=0; i<len; i++)
    {
        ret*=10;
        ret=ret+(*(p+i)-0x30);
    }
    return ret * sign;
}