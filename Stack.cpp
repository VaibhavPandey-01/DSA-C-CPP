#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<"Prints top most value of the stack : "<<s.top()<<endl;
    cout<<"Prints Size of the Stack : "<<s.size()<<endl;
    s.pop();
    cout<<"New Top after pop() : "<<s.top()<<endl;
    if(!s.empty())
        cout<<"Stack is not empty "<<endl;
    return 0;
 }