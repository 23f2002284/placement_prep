#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
Given two arrays, val[] and wt[] , representing the values and weights of items, and 
an integer capacity representing the maximum weight a knapsack can hold, 
determine the maximum total value that can be achieved by putting items in the knapsack. 
You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Approach:
1. Create a vector of pairs where each pair contains the value and weight of an item.
2. Sort the vector in descending order of value/weight ratio.
3. Initialize a variable to store the total value.
4. Iterate through the sorted vector and add the value of each item to the total value.
5. Return the total value.

Why greedy
- given we have to bag maximum value then we will bag maximum value first
- and if we can't bag the whole item then we will bag the fraction of item 


capacity to limit weights while bagging maximum value

we will have 2 approach
1. sort with cmp function
2. sort with priority queue
*/


// approach - 1
bool cmp(pair<int, int> a, pair<int, int> b){
    return (double)a.first/a.second > (double)b.first/b.second;

    // interview grade correction
    // return (long double)a.first/a.second > (long double)b.first/b.second;
}
double fractional_knapsack(vector<int> val, vector<int> wt, int capacity){
    // time complexity: O(nlogn)
    // space complexity: O(n)
    vector<pair<int, int>> items;
    for(int i=0; i<val.size(); i++){
        items.push_back({val[i], wt[i]});
    }

    double total_value = 0;
    sort(items.begin(), items.end(), cmp);
    
    for(int i=0; i<items.size(); i++){
        if(capacity >= items[i].second){
            total_value += items[i].first;
            capacity -= items[i].second;
        }
        else{
            total_value += (double)items[i].first * capacity / items[i].second;
            break;
        }
    } 
    // rounded up to 6 decimal places ( GFG compares floating values with precision tolerance )
    return total_value;
}

// approach - 2
double fractional_knapsack_approach_2(vector<int> val, vector<int> wt, int capacity){
    // time complexity: O(nlogn)
    // space complexity: O(n)
    // this approach is like a overkill ha ha
    priority_queue<pair<double, pair<int, int>>> pq;
    for(int i=0; i<val.size(); i++){
        pq.push({(double)val[i]/wt[i], {val[i], wt[i]}});
    }
    
    double total_value = 0;
    while(capacity > 0 && !pq.empty()){
        pair<double, pair<int, int>> temp = pq.top();
        pq.pop();
        
        double per = temp.first;
        int val1 = temp.second.first;
        int wt1 = temp.second.second;
        
        if(capacity >= wt1){
            total_value += val1;
            capacity -= wt1;
        }
        else{
            total_value += per * capacity;
            capacity = 0;
            // break // we could have used break as well
        }
    }
    // rounded up to 6 decimal places ( GFG compares floating values with precision tolerance )
    return total_value;
}

int main(){
    vector<int> val={500};
    vector<int> wt={30};
    int capacity = 10;
    cout<<fractional_knapsack_approach_2(val, wt, capacity)<<endl;
    return 0;
}
