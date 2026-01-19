#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

*/

class Solution {
  public:
  static int findPivot(vector<int>& arr){
      int s = 0;
        int e = arr.size()-1;
        
        while(s<e){
            int mid = s + (e-s)/2;
            if(arr[mid] >= arr[0]){
                s = mid+1;
            }
            else{
                e = mid;
            }
        }
        return s;
  }
  static int binarySearch(vector<int>& arr,int s, int e, int key){
      
      while(s<=e){
          int mid = s + (e-s)/2; 
          if (arr[mid]==key){
              return mid;
          }
            if(arr[mid] > key){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
  }
    int search(vector<int>& arr, int key) {
        // Code Here
        // find pivot element first then do binary search of the right sorted arrary
        
        int pivot = findPivot(arr);
        if(arr[pivot] <= key && key <= arr[arr.size()-1]){
            return binarySearch(arr, pivot, arr.size()-1, key);
        }
        else{
            return binarySearch(arr, 0, pivot-1, key);
        } 
        
    }
};

int main(){
    Solution s;
    vector<int> arr = {4,5,6,7};
    int key = 6;
    cout << s.search(arr, key) << endl;
    return 0;
}