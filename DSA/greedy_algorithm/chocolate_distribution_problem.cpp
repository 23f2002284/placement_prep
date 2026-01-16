#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that -
    i. Each student gets exactly one packet(where each packet have different number of chocolate).
    ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.

Basically, we have to return minimum difference between maximum and Minimum number of chocolate in window of m
Sliding window problem ?
*/

int main(){
    vector<int> chocolates={3, 4, 1, 9, 56, 7, 9, 12};
    sort(chocolates.begin(), chocolates.end());
    int students=5;
    int mini = INT_MAX;
    int start = 0;
    int end = students-1;
    while(end < chocolates.size()){
        int diff = chocolates[end] - chocolates[start];
        start++;
        end++;
        mini = min(diff, mini);
    }
    cout << mini << endl;
    return 0;
}