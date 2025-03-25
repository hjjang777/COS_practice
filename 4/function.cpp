#include <iostream>
#define BUFLEN 30
using namespace std;
void print_result(int *arr, int idx){
    cout<<"arr["<<idx<<"]: " << arr[idx] << endl;
}
int main(int argc, char *argv[]){
    // int arr[10];
    int arr[BUFLEN];
    int i;
    for (i=0;i<10;i++){
        arr[i]=10-i;
    }
    // cout<<"arr[0]: " << arr[0] << endl;
    print_result(arr, 0);
    // cout<<"arr[3]: " << arr[3] << endl;
    print_result(arr, 3);
    // cout<<"arr[7]: " << arr[7] << endl;
    print_result(arr, 7);
    return 0;
}