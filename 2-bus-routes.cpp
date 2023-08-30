

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, blueCost;
    cin>>n;
    vector<int> red(n), blue(n);
    for(int i=0; i<n; i++){
        cin>>red[i];
    }
    for(int i=0; i<n; i++){
        cin>>blue[i];
    }
    cin>>blueCost;
    vector<int> result(n+1);
    result[0] = 0;

    vector<vector<int>> dp(n+1, vector<int>(2));  
    dp[0][0] = 0;
    dp[0][1] = blueCost;  

    for(int i=1; i<=n; i++){
        dp[i][0] = min(dp[i-1][0] + red[i-1], dp[i-1][1]+red[i-1]);
        dp[i][1] = min(dp[i-1][1] + blue[i-1], dp[i-1][0] + blue[i-1] + blueCost);
        result[i] = min(dp[i][0], dp[i][1]);
    }

    for(int i=0; i<=n; i++){
        cout<<result[i]<<" ";
    }
}