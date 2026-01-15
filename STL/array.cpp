#include<iostream>
#include<array>
using namespace std;

int main(){
    array<int, 6> arr;  

    for (int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    // size
    cout<<"Size of array : "<<arr.size()<<endl;

    // empty
    cout<<"Array is empty or not : "<<arr.empty()<<endl;

    // front
    cout<<"First element : "<<arr.front()<<endl;

    // back
    cout<<"Last element : "<<arr.back()<<endl;

    // fill
    arr.fill(1);
    for (int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

    // swap
    array<int, 6> arr2;
    arr2.fill(2);
    arr.swap(arr2);
    for (int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    
    // at
    cout<<"Element at index 2 : "<<arr.at(2)<<endl;

    // begin
    cout<<"First element : "<<*arr.begin()<<endl;

    // end
    cout<<"Last element : "<<*arr.end()<<endl;


    return 0;
}