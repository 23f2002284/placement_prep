#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

*/

class Solution {
    static long long int sqrtInteger(int x){
        int s = 0;
        int e = x;
        long long int ans = -1;
        while(s<=e){
            long long int mid = s + (e-s)/2;
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid < x){
                ans = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    static double sqrtPrecision(int x, int precision){

        double frac = 1;
        double ans = sqrtInteger(x);
        for(int i = 0; i<precision; i++){
            frac = frac/10;
            for(double j = ans; j*j<=x; j+=frac){
                ans = j;
            }
        }
        return ans;
    }
  public:
    double mySqrt(int x) {
        // code here
        return sqrtPrecision(x, 3);
    }
};

int main(){
    Solution s;
    int x = 8;
    cout << s.mySqrt(x) << endl;
    return 0;
}