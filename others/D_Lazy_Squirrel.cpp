#include <bits/stdc++.h>

using namespace std;

#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

vector<int> v[1000002];
int ara[1000002];

int N = 0;
string st;
string st1;
void dfs(int n, int m)
{
    ara[n] = 1;

    if (n == 1) N++;

    for (auto va : v[n])
    {
        int m_fix=m;
        if (ara[va] != 1)
        {
            m= m_fix;
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
                            if (m == 0)
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

            // bug(n,m);
            dfs(va, m);
            st1.pop_back();
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        N = 0;

        cin >> st;
        st1.clear();

        for (int j = 1; j < n; j++)
        {
            int g, f;
            cin >> g >> f;
            v[g].push_back(f);
            v[f].push_back(g);
        }
        st1.push_back(st[0]);
        dfs(1, 1);
        cout << "Case " << i << ": " << N << "/" << n << "\n";
        // cout<<N<<endl;
    }
}