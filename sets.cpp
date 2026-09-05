#include<iostream>
#include<set>
#include<unordered_set>
// Sets are always sorted and unique

using namespace std;
int main(){
    set<int> s1;
    s1.insert(3);
    s1.emplace(4);
    s1.emplace(1);
    s1.emplace(2);
    s1.emplace(5);
    s1.emplace(5);
    for(auto val :s1){
        cout<<val<<" ";
    }
    auto it = s1.find(2);// if it won't find the element it will point to the end element 
    // cout<<*it<<endl;
    cout<<s1.count(5);
    s1.erase(5); // take O(log n) time
    cout<<endl;
    for(auto val :s1){
        cout<<val<<" ";
    }
    // erase in row :
    auto it1 = s1.find(1);
    auto it2 = s1.find(3);
    s1.erase(it1,it2); // excludes it2
    cout<<endl;
    for(auto val :s1){
        cout<<val<<" ";
    }


    //In multiset the elements are sorted but duplicate values are allowed
    multiset<int> m1;
    m1.insert(3);
    m1.emplace(4);
    m1.emplace(1);
    m1.emplace(2);
    m1.emplace(5);
    m1.emplace(5);
    cout<<endl;
    for(auto val :m1){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<m1.count(5);

    // in unordered set , ordered is not maintained but only unique elements are allowed else everything is same
    //except upper bound and lower bound functions
    // every operation is done in O(1)
    unordered_set<int> us;
    us.insert(3);
    us.emplace(4);
    us.emplace(1);
    us.emplace(2);
    us.emplace(5);
    us.emplace(5);
    cout<<endl;
    for(auto val :us){
        cout<<val<<" ";
    }
    cout<<endl;
    
    
    return 0;
 }