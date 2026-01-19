#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
  static int firstOcc(vector<int>& arr, int x){
      int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        
        int firstOcc = -1;
        while(s <= e){
            if(arr[mid]==x){
                firstOcc = mid;
                e = mid-1;
            }
            else if(arr[mid] > x){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return firstOcc;
  }
  static int lastOcc(vector<int>& arr, int x){
      int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        
        int lastOcc = -1;
        while(s<=e){
            if(arr[mid]==x){
                lastOcc = mid;
                s = mid+1;
            }
            else if(arr[mid] > x){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return lastOcc;
  }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        return {firstOcc(arr, x), lastOcc(arr, x)};
    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 2, 2, 2, 2, 3, 4};
    int x = 2;
    vector<int> result = s.find(arr, x);
    cout << "First occurrence: " << result[0] << endl;
    cout << "Last occurrence: " << result[1] << endl;
    return 0;
}