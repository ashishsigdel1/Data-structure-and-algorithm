#include <iostream>
using namespace std;

int main(){
    int a[5] = {5,4,2,16,3}, pos, i;
    cout <<"Enter the position: ";
    cin>>pos;
    for(i=pos; i<5; i++){
        a[i] = a[i+1];
    }
    cout<<"New arrat: ";
    for(i=0; i<4; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}