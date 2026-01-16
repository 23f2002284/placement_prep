#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    //binary search tree
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 5;
    auto it = binary_search(v.begin(), v.end(), key);
    if(it){
        cout << "Element is present" << endl;
    }
    else{
        cout << "Element is not present" << endl;
    }

    // lower bound
    auto it2 = lower_bound(v.begin(), v.end(), key)-v.begin();
    cout << "Lower bound of " << key << " is " << it2 << endl;

    // upper bound
    auto it3 = upper_bound(v.begin(), v.end(), key);
    cout << "Upper bound of " << key << " is " << *it3 << endl;

    int a = 5;
    int b = 7;
    cout << "Max of " << a << " and " << b << " is " << max(a, b) << endl;
    cout << "Min of " << a << " and " << b << " is " << min(a, b) << endl;
    
    // swap
    swap(a, b);
    cout << "After swap a = " << a << " and b = " << b << endl;
    
    //reversed
    cout << "Original array : ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Reversed array : ";
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    string c = "abc";
    cout << "Original string : " << c << endl;
    reverse(c.begin(), c.end());
    cout << "Reversed string : " << c << endl;

    // rotate
    rotate(v.begin(), v.begin()+3, v.end());
    cout << "Rotated array : ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // sort
    sort(v.begin(), v.end());
    cout << "Sorted array : ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}