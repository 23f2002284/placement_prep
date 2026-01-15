#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> s;
    // push
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // pop
    s.pop();

    // top
    cout<<"Top element : "<<s.top()<<endl;

    // size
    cout<<"Size of stack : "<<s.size()<<endl;

    // empty
    cout<<"Is stack empty : "<<s.empty()<<endl;

    // print stack
    while (!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    // print with for loop
    for (int i = 0; i < s.size(); i++) {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}