#include <iostream>
using namespace std;
int main(int argc, char *argv[]){
    int x,y,i,cnt;
    cout<<"Put 2 interger"<<endl;
    cin >> x;
    cin >> y;
    // x=atoi(argv[1]);
    // y=atoi(argv[2]);
    if (x < y) {
        cnt=0;
        // i=x;
        // while (i<y){
        //     cnt=cnt+i;
        //     i++;
        // }
        for (i=x;i<y+1;i++){
            cnt+=i;
            // cout << cnt << endl;
        }
        cout<<"Sum of number: "<<cnt<<endl;
    } 
    else{
        cout<<"Exit the program..."<< endl; 
    }
    
    return 0;
}