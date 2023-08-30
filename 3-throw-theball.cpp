// https://leetcode.com/discuss/interview-question/3796460/Oracle-OA-or-On-Campus

#include <bits/stdc++.h>
using namespace std;

int findval(vector<int>& arr, int sec){
    int n = arr.size();
    unordered_map<int, int> mp;
    vector<int> visited(n+1, -1);
    int next  = 1, t = 0;

    while(visited[next] == -1){
        if(t == sec)
            return next;     
        mp[t] = next;
        visited[next] = t;
        t++;
        next = arr[next-1];
    }

    int cycle = t - visited[next];
    sec -= visited[next];
    sec %= cycle;
    sec += visited[next];
    return mp[sec];
}

int main()
{
    int n, sec;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> sec;
    cout << findval(arr, sec);
    return 0;
}