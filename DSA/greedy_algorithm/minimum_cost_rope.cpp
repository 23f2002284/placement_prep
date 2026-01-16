#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. 
The cost to connect two ropes is the sum of their lengths. 
Return the minimum total cost.
# Logic
as minimum cost associate minimum length ropes
we first sort the array and then connect the first two ropes and push the sum in the array
but repitively sorting is not efficient so we have to use min heap to get minimum element in O(1) time
we push the sum in min heap and then connect the first two ropes and push the sum in the array and 
each time we will count the cost
until we get only one rope and we will return the cost
*/

int main(){
    vector<int> ropes = {4, 3, 2, 6};
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < ropes.size(); i++){
        minHeap.push(ropes[i]);
    }
    int cost = 0;
    while(minHeap.size() > 1){
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        int sum = first + second;
        cost += sum;
        minHeap.push(sum);
    }
    cout << "Minimum cost to connect all ropes is " << cost << endl;
    return 0;
}
