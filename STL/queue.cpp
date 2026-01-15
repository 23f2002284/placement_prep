#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    cout<<"Front element : "<<q.front()<<endl;
    cout<<"Back element : "<<q.back()<<endl;
    
    q.pop();
    cout<<"Front element : "<<q.front()<<endl;
    cout<<"Back element : "<<q.back()<<endl;
 
    // empty
    cout<<"Queue is empty or not : "<<q.empty()<<endl;

    // size
    cout<<"Size of queue : "<<q.size()<<endl;

    // print queue
    while (!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    // for loop
    for (int i=0; i<q.size(); i++) {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    // front
    cout<<"Front element : "<<q.front()<<endl;

    // back
    cout<<"Back element : "<<q.back()<<endl;
    return 0;
}