#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;
    cin>>row>>col;

    vector<vector<int>> grid(row, vector<int>(col));

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>> dp(row, vector<int>(col, 0));
    int size = 0;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(!i || !j || grid[i][j] == 0){
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
            size = max(size, dp[i][j]);
        }
    }

    cout<<size*size;

}