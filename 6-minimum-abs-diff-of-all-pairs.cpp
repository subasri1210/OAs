// https://leetcode.com/discuss/interview-question/2443810/Oracle-OA

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {4,2,1,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n);
    int l = 0;
    int r = 0;
    int mul = -1;
    for(int i = 1; i < n; i++){
      r += mul * arr[i];
      mul *= -1;      
    }
    int ans = l + r;
    mul = 1;
    l = -arr[0];
    for(int i = 1; i < n; i++){
      r += mul * arr[i];
      ans = min(ans, l + r);
      l += mul*arr[i];
      mul *= -1;
    }
    cout << "ans: " << ans << endl;
}