#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

int rec(int i, int maxim, vector<int> &v, vector<vector<int>> &dp){
    maxim = log10(maxim);

    if (i < 0) return 0;
    if (dp[i][maxim] != -1) return dp[i][maxim];

    int ans = rec(i-1, max((int)powl(10, maxim), v[i]), v, dp);
    if (v[i] < powl(10, maxim)) ans -= v[i];
    else ans += v[i];

    return dp[i][maxim] = ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string in;
        cin >> in;
        int n = in.size();

        vector<int> v;
        for (int i = 0; i < n; i++)
            if (in[i] == 'A') v.push_back(1);
            else if (in[i] == 'B') v.push_back(10);
            else if (in[i] == 'C') v.push_back(100);
            else if (in[i] == 'D') v.push_back(1000);
            else v.push_back(10000);

        vector<int> maxi(n);
        maxi[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; i--) maxi[i] = max(maxi[i + 1], v[i]);

        vector<int> postsum(n);
        postsum[n - 1] = v[n - 1];
        for (int i = n - 2; i >= 0; i--)
            if (maxi[i + 1] > v[i]) postsum[i] = postsum[i + 1] - v[i];
            else postsum[i] = postsum[i + 1] + v[i];

        vector<vector<int>> dp(n, vector<int>(5, -1));
        int ans = 10000;
        if (1 < n) ans += postsum[1];

        for (int i = 1; i < n-1; i++)
            for (int j = 1; j <= 10000; j *= 10)
            {
                int temp = rec(i-1, max(j, maxi[i+1]), v, dp);
                if (maxi[i+1] > j) temp -= j;
                else temp += j;
                temp += postsum[i+1];

                ans = max(temp, ans);
            }
        for (int j = 1; j <= 10000; j *= 10)
        {
            int temp = rec(n-2, j, v, dp);
            temp += j;

            ans = max(temp, ans);
        }

        cout << ans << endl;
    }
}