#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*

*/

int binarySearch(vector<int>& arr, int key){
    int s = 0;
    int e = arr.size()-1;
    
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int key = 6;
    cout << "Element is at index: " << binarySearch(arr, key) << endl;
    return 0;
}