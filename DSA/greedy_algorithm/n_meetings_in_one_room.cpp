#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * n meetings in one room 
 * in form of (start_time, end_time)
 * return maximum number of meetings that can be held in that room
 * start time can't be same as end time of another meeting
 */ 

// Existing template

// class Solution {
//     public:
//         // Function to find the maximum number of meetings that can
//         // be performed in a meeting room.
//         int maxMeetings(vector<int>& start, vector<int>& end) {
//             // Your code here
                
//     }   
// };  

// Submission friendly
class Solution{
    public:
        int maxMeetings(vector<int>& start, vector<int>& end){
            // vector of two element start and corresponding end
            vector <pair<int, int>> meetings; // why pair ?
            for(int i = 0; i<start.size();i++){
                meetings.push_back({end[i], start[i]});
            }
            
            // sort the w.r.t end
            sort(meetings.begin(), meetings.end());
            // count and check prev end < next start to increment
            int count = 1; // initialization with 1 as 
            int lastEndTime = meetings[0].first;
            for(int i = 0; i <meetings.size();i++){
                if(meetings[i].second > lastEndTime){
                    count++;
                    lastEndTime = meetings[i].first;
                }
            }
            return count;
        }
}

// Not submission friendly

// approach - 1 