#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> maxi; //max heap
    priority_queue<int, vector<int>, greater<int>> mini; //min heap
    maxi.push(1);
    maxi.push(2);
    maxi.push(3);
    maxi.push(4);
    maxi.push(5);
    
    cout<<"Front element : "<<maxi.top()<<endl;
    
    maxi.pop();
    cout<<"Front element : "<<maxi.top()<<endl;
 
    // print priority queue
    while (!maxi.empty()) {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;
    // int n = maxi.size();
    // // for loop print
    // for (int i=0; i<n; i++) {
    //     cout<<maxi.top()<<" ";
    //     maxi.pop();
    // }
    // cout<<endl;

    mini.push(1);
    mini.push(2);
    mini.push(3);
    mini.push(4);
    mini.push(5);
    
    cout<<"Front element : "<<mini.top()<<endl;
    
    mini.pop();
    cout<<"Front element : "<<mini.top()<<endl;
 
    // print priority queue
    while (!mini.empty()) {
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;
    // int n = mini.size();
    // // for loop print
    // for (int i=0; i<n; i++) {
    //     cout<<mini.top()<<" ";
    //     mini.pop();
    // }
    // cout<<endl;

    return 0;
}