// https://www.thejoboverflow.com/p/p1637/

#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void getFactors(int num, vector<int>& freq){
    for(int i=1; i<=sqrt(num); i++){
        if(num%i == 0){
            if(num/i == i){
                freq[i]++;
            }
            else {
                freq[i]++;
                freq[num/i]++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin>>n;

    vector<int> keys(n);

    for(int i=0; i<n; i++){
        cin>>keys[i];
    }
    
    cin>>q;

    int sz = 1e6+1;

    vector<int> freq(sz, 0);

    for(int i=0; i<keys.size(); i++){
        getFactors(keys[i], freq);
    }

    vector<int> pref(sz, 0);

    for(int i=1; i<pref.size(); i++){
        pref[i] = pref[i-1] + (freq[i]*freq[i]);
    }

    for(int i=0; i<q; i++){
        int x, y;
        cin>>x>>y;
        cout<<pref[y] - pref[x-1]<<endl;
    }
}