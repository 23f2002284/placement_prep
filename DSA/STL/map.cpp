#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    // same key can't point to different values but different keys can point to same values 
    // ordered map search time is log(n) because of implementation of red black tree or self balancing binary search tree
    // unordered map search time is O(1) on average but O(n) in worst case because of implementation of hash table
    map<int, int> mpp; // ordered map
    mpp[1] = 1;
    mpp[2] = 2;
    mpp[3] = 3;
    mpp[4] = 4;
    mpp[5] = 5;
    mpp[5] = 6; // it will update the value of key 5
    mpp[1] = 7; // it will update the value of key 1
    
    for(auto i : mpp){
        cout << i.first << " " << i.second << endl;
    } cout << endl;


    // erase
    mpp.erase(5); // only key is used to delete the element
    for(auto i : mpp){
        cout << i.first << " " << i.second << endl;
    } cout << endl;

    // insert function
    mpp.insert({6, 6});
    for(auto i : mpp){
        cout << i.first << " " << i.second << endl;
    } cout << endl;

    // size
    cout << "Size of map : " << mpp.size() << endl;

    // empty
    cout << "Map is empty or not : " << mpp.empty() << endl;

    // find function
    auto it = mpp.find(2);
    if(it != mpp.end()){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }

    // count 
    cout << "Count of 2 : " << mpp.count(2) << endl;

    // unordered map
    unordered_map<int, int> umpp;
    umpp[1] = 1;
    umpp[2] = 2;
    umpp[3] = 3;
    umpp[4] = 4;
    umpp[5] = 5;
    umpp[5] = 6; // it will update the value of key 5
    umpp[1] = 7; // it will update the value of key 1
    
    for(auto i : umpp){
        cout << i.first << " " << i.second << endl;
    } cout << endl;

    return 0;

}
