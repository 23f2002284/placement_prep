#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
Given a sentences, reverse the string word by word
split  -> reverse -> merge with '.'

words are separated by "." sign
*/


int main(){
    string s = "I.am.pratyush";
    vector<string> v;
    string str = "";
    for(int i = 0; i<s.length();i++){
        if(s[i] != '.'){
            str+= s[i];
        }
        else{
            v.push_back(str);
            str = "";
        }
    }
    reverse(v.begin(), v.end());

    for(int i = 0; i<v.size();i++){
        str += "." + v[i];
    }
    cout << str << endl;
    return 0;
}