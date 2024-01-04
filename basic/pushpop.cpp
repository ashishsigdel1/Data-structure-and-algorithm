#include<iostream>
using namespace std;
class Stack{
private:
int size;
int top;
int *arr;
int item;
public:
Stack(int size){
    this->size=size;
    top=-1;
    arr=new int[size];
}
void push(int x){
    if(top==size-1){
        cout<<"Stack is Full"<<endl;
    }
    else{
        top++;
        arr[top]=x;
    }
}
int pop(){
    if(top==-1){
        cout<<"Stack is empty";
    }
    else{
    item= arr[top];
        top--;
        return item;
    }
}
void display(){
    for(int i=top;i>=0;i--){
    cout<<arr[i]<<" ";
    }
    cout<<endl;
}

};
int main(){
int item;
Stack s(3);
s.push(12);
s.push(5);
s.push(64);
s.display();
cout<<s.pop()<<endl;
s.display();

}