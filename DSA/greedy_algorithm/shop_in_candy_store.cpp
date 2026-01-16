#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
In a candy store, there are different types of candies available and prices[i] represent the price of  ith types of candies. 
You are now provided with an attractive offer.
For every candy you buy from the store, you can get up to k other different candies for free. Find the minimum and maximum amount of money needed to buy all the candies.
Note: In both cases, you must take the maximum number of free candies possible during each purchase.
*/

int main(){
    vector<int> prices={1, 2, 3, 4};
    int k=2;
    // for minimum cost
    sort(prices.begin(), prices.end());
    int i = 0;
    int j = prices.size()-1;
    int min_cost = 0;
    while(i <= j){
        min_cost += prices[i];
        i++;
        j -= k;
    }
    cout << "Minimum cost is " << min_cost << endl;

    int max_cost = 0;
    i = prices.size()-1;
    j = 0;

    while(j <= i ){
        max_cost += prices[i];
        j += k;
        i--;
    }
    cout << "Maximum cost is " << max_cost << endl;

    return 0;
}