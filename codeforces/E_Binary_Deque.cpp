#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n, s;
        vector<int> index;
        cin >> n >> s;
        int ara[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ara[i];
            if (ara[i])
                index.push_back(i);
        }
        int sum = index.size();
        if (sum == s)
        {
            cout << 0 << endl;
            continue;
        }
        else if (sum < s)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            int check = sum - s;
            int min = 2e5;
            for (int i=check; i>=0; i--){
                int front = i!=0? index[i-1]+1 : 0;
                int back = check-i!=0? n-index[sum-check+i] : 0;
                int work = front + back;
                if (work<min) min = work;
            }
            cout << min << endl;
        }
    }
    return 0;
}