#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(99);
    q.push(88);
    q.push(77);
    q.push(66);
    q.push(55);
    q.pop();
    cout<<q.empty()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    return 0;
 }