#include <iostream>
using namespace std;
int main(int argc, char *argv[]){
    int x{};
    cout<<"Enter a number: ";
    cin>>x;

    switch (x){
        case 1:
            cout<<"You enter 1"<<endl;
            break;
        case 2:
            cout<<"You enter 2"<<endl;
            break;
        default:
            cout<<"You enter other number"<<endl;
            break;
    }
    return 0;
}