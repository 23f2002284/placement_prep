#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
# Activity Selection Problem
You are given a set of activities, 
each with a start time and a finish time, represented by the arrays start[] and finish[], respectively. 
A single person can perform only one activity at a time, meaning no two activities can overlap. 

Your task is to determine the maximum number of activities that a person can complete in a day.

// Similar to Meeting in one room problem

*/

int main(){
    vector<int> start={1,3,0,5,8,5};
    vector<int> finish={2,4,6,7,9,9};
    
    vector<pair<int, pair<int, int>>> activities;
    for(int i=0; i<start.size(); i++){
        activities.push_back({finish[i], {start[i], i+1}});
    }

    // sort the vector
    sort(activities.begin(), activities.end());
    
    vector<int> ans;
    int LastFinishTime = activities[0].first;
    ans.push_back(activities[0].second.second);
    
    for(int i=1; i<activities.size(); i++){
        if(activities[i].second.first >= LastFinishTime){
            ans.push_back(activities[i].second.second);
            LastFinishTime = activities[i].first;
        }
    }
    // sort the ans vector
    sort(ans.begin(), ans.end());
    
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}