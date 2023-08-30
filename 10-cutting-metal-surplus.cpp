// https://leetcode.com/discuss/interview-question/428244/audible-oa-2019-cutting-metal-surplus

#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int cost_per_cut, metal_price, n;

    cin>>cost_per_cut>>metal_price>>n;

    vector<int> rods(n);

    for(int i=0; i<n; i++){
        cin>>rods[i];
    }

    int maxLen = *max_element(rods.begin(), rods.end());
    int maxProfit = 0;

    for(int i=1; i<=maxLen; i++){
        int prevSum = 0;
        for(int length : rods){
            int cuts  = 0, waste = 0;

            if(length%i == 0){
                cuts += (length/i) - 1;
            } else {
                cuts += (length/i);
            }

            waste = length%i;
            int profit = max(
                prevSum, 
                prevSum + (length*metal_price - cuts*cost_per_cut - waste*metal_price)
            );
            prevSum = profit;
        }
        maxProfit = max(maxProfit, prevSum);
    }

    cout<<maxProfit;
    
}