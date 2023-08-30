// https://leetcode.com/discuss/interview-question/3791675/Oracle-OA

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    logic - at every start day of event I will check how many events are going on by checking is the start day of event 'i' lie in the range of start and end day of event j if yes then i will push the points associated to it into my priority queue and then will take the min(k or q.size())
    tc- O(n*(n+log(k)))
    sc-O(n)
    */

    int n;
    cin >> n;
    int d;
    cin >> d;
    int k;
    cin >> k;
    vector<int> s(n);
    vector<int> e(n);
    vector<int> p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> e[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int day = s[i];
        int cnt = 0;
        priority_queue<int> values;
        for (int j = 0; j < n; j++)
        {
            if (s[i] >= s[j] && s[i] <= e[j])
            {
                values.push(p[j]);
            }
        }
        int t = k;
        while (t-- && !values.empty())
        {
            cnt += values.top();
            values.pop();
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}