#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Given N jobs with their deadlines and profits, find the maximum profit that can be obtained by completing the jobs within their deadlines.

Approach:
1. Sort the jobs in descending order of their profits.
2. Initialize a boolean array to keep track of the time slots.
3. Iterate through the sorted jobs and try to schedule each job at the latest possible time slot before its deadline.
4. If a time slot is available, schedule the job and add its profit to the total profit.
5. Return the total profit.

Time Complexity: O(N log N) - for sorting
Space Complexity: O(N) - for the boolean array
*/

// o(n^2)
vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        
        vector<pair<int, pair<int, int>>> jobs;
        
        for(int i = 0; i<n; i++){
            jobs.push_back({profit[i], {deadline[i], i}});
        }
        
        sort(jobs.rbegin(), jobs.rend()); // decreasing order
        
        int max_deadline = 0;
        for(int i = 0; i< n; i++){
            if(jobs[i].second.first > max_deadline){
                max_deadline = jobs[i].second.first;
            }
        }
        
        vector<bool> timeslots(max_deadline+1, false);
        
        int count = 0;
        int total_profit = 0;
        
        for(int i = 0; i< n; i++){
            for(int j = min(max_deadline,jobs[i].second.first); j >= 1;j--){
                if(!timeslots[j]){
                    timeslots[j] = true;
                    total_profit += jobs[i].first;
                    count ++;
                    
                    break;
                }
            }
        }
        return {count, total_profit};
    }


vector<int> jobSequencing_app2(vector<int> &deadline, vector<int> &profit){
    
}



int main() {
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};
    
    vector<int> result = jobSequencing(deadline, profit);
    cout << "Number of jobs: " << result[0] << endl;
    cout << "Maximum profit: " << result[1] << endl;
    
    return 0;
}