#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
Geekina got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. 
Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive.
*/


int main(){
    int n=27,s=27,m=2;
    // if unit of food i can buy is less than unit of food required to survive then it is not possible to survive
    if(n<m){
        cout<<-1<<endl;
    }
    // if number of days is more than equals to 7 and (n-m)*6 < m then it is not possible to survive
    if(s>=7 && (n-m)*6 < m){
        cout<<-1<<endl;
    }
    
    int buying_days = s - s/7;
    int total_food = s * m;
    
    int ans = 0;
    if(total_food % n == 0){
        ans = total_food / n;
    }
    else{
        ans = (total_food / n) + 1;
    }
    
    if(ans <= buying_days){
        cout<<ans<<endl;
    }
    else{
        cout<<-1<<endl;
    }

    return 0;
}