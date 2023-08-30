// https://www.interviewbit.com/problems/count-good-subsequences/

int Mod = 1'000'000'007;

int ncr(int n, int r)
{
    int sum = 1;

    for (int i = 1; i <= r; i++)
    {
        sum = ((1LL * sum * (n - r + i)) % Mod) / i;
        sum = sum % Mod;
    }
    return (int)sum;
}

int Solution::solve(vector<int> &s)
{
    map<int, int> freq;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        freq[s[i]]++;
    }

    int max_freq = 0;
    for (int i = 0; i < n; i++)
    {
        max_freq = max(max_freq, freq[s[i]]);
    }
    int ans = 0;

    for (int i = 1; i <= max_freq; i++)
    {
        int temp = 1;
        for (auto x : freq)
        {
            if (x.second >= i)
            {
                temp = (1LL * temp * (ncr(x.second, i) + 1)) % Mod;
            }
        }
        ans = (ans + temp - 1 + Mod) % Mod;
    }
    return ans;
}