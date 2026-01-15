#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(5);
    s.insert(1);

    for(auto i : s){
        cout << i << endl;
    } cout << endl;

    s.erase(s.begin()); // erase first element

    set<int>:: iterator it = s.begin(); // 
    it++;
    s.erase(it); // erase second element ( technically the third element from earlier set )

    for(auto i : s){
        cout << i << endl;
    } cout << endl;

    cout << "Size of set : " << s.size() << endl;

    cout << "5 is present or not : " << s.count(5) << endl; // give 1 if element is present else 0
    
    // find
    // it returns iterator to the element if found else returns iterator to end
    set<int>:: iterator h = s.find(2);
    cout << "2 is present or not : " << *h << endl;

    cout << "h is a iterator to " << *h << endl;

    for (auto i = h; i != s.end(); i++){
        cout << *i << endl;
    } cout << endl;

    // lower bound
    set<int>:: iterator lb = s.lower_bound(4); // returns iterator to the first element >= 4
    cout << "Lower bound of 4 : " << *lb << endl;

    // upper bound
    set<int>:: iterator ub = s.upper_bound(4); // returns iterator to the first element > 4
    cout << "Upper bound of 4 : " << *ub << endl;



    return 0;


}