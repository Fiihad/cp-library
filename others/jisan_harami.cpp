#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);


vector<int> v[1000002];
int ara[1000002];

int N = 0;
string st;
string st1;
void dfs(int n, int m)
{
    ara[n] = 1;

    if (m == 1){
        N++;
    }

    int m_fix = m;
    for (auto va : v[n])
    {
        if (ara[va] != 1)
        {
            m = m_fix;
            st1.push_back(st[va - 1]);
            if (st1.size() == 2)
            {
                if (st1[0] == st1[1])
                    m = 1;
                else
                    m = 2;
            }
            else
            {
                if (m == 1)
                {
                    if (st1.back() != st1[0])
                    {
                        m = st1.size();
                    }
                }
                else
                {

                    if (st1.back() != st1[m - 1])
                    {
                        if (st1.back() == st1[m - 2])
                        {
                            m -= 2;
                            if (m <= 1)
                            {
                                N++;
                                m = st1.size();
                            }
                        }
                        else
                            m = st1.size();
                    }
                }
            }

            // bug(n,m,st1,N);
            dfs(va, m);
            st1.pop_back();
        }
    }
}

int main()
{
    fast;

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        N = 0;
        cin >> st;
        st1.clear();
        for (int j = 0; j <= n + 1; j++)
            ara[j] = 0;
        for (int j = 1; j < n; j++)
        {
            int g, f;
            cin >> g >> f;
            v[g].push_back(f);
            v[f].push_back(g);
        }
        st1.push_back(st[0]);
        dfs(1, 1);
        // bug(N);
        cout << "Case " << i << ": " << N << "/" << n << "\n";
    }
}