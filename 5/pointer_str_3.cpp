#include <iostream>
#define BUFLEN 10
using namespace std;

int main(int argc, char *argv[]){
    char str1[6]={'h','e','l','l','o',0};
    // 0: null character or '\0'
    // It means the end of the string.
    // If we change the value of the null character, the str1 will print untill it meet the new null character.
    // char str2[6]={'w','o','r','l','d',0};
    char *p;
    int i;
    p=str1+6;
    cout<<"str1= " << str1 << endl;
    // cout<<"str2= " << str2 << endl;
    // cout<<"p= " << p << endl;
    // for (int i=-10;i<10;i++){
    //     cout<<"p["<<i<<"]= " << p[i] << endl;
    // }

    // &str1=&str1+p;
    // str1=str1,p;
    *(p-1)=',';

    cout<<"str1= " << str1 << endl;

    return 0;
}