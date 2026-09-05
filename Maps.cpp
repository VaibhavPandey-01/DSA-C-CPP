#include<iostream>
#include<map>
#include<string>

//Map stores unique key values and in sorted order 

using namespace std;

int main(){
    map<string,int> student = {{"Yash",7800},{"Yukta",05555},{"Ritesh",8088},{"Vaibhav",500}};
    student.insert({"Yanshika",01276});
    map<string,int> :: iterator itr;
    for(itr = student.begin(); itr!=student.end();itr++){
        cout<<(*itr).first<<" "<<(*itr).second<<"\n";
    }
    cout<<"Max Size "<<student.max_size()<<endl;
    cout<<"Size "<<student.size()<<endl;
    cout<<"Empty "<<student.empty()<<endl;

    // multimap - allows to store duplicate key in sorted order , else operations are same 
    // unordered_map - does not allow to store duplicate keys and does not stores in sorted order, else operations are same 


    return 0;
}