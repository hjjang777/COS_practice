#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    unsigned int x{};
    cout<< "Enter a number: ";
    cin>>x;
    if (x>=0){
        cout<<"You enter a positive interger!"<<endl;

    } else{
        cout<< "You enter a negative interger!"<<endl;
    }
    return 0;
    
}