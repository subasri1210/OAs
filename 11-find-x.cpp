// https://www.thejoboverflow.com/p/p581/

#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b, c, x = 0;

    cin>>a>>b>>c;

    for(int i=0; i<=31; i++){
        if(!((1<<i) & c)){
            if(((1<<i) & a) && ((1<<i) & b)){
                cout<<"-1";
                exit(0);
            }
        }
        else if(((1<<i) & c)){
            if(!((1<<i) & a) || !((1<<i) & b)){
                x += pow(2, i);
            }
        }
    }

    cout<<x;
    
}