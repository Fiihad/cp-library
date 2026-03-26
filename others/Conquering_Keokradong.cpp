#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        int n, k, input, min;
        cin >> n >> k;
        vector<int> ara;
        for (int i=0; i<=n; i++){
            cin >> input;
            ara.push_back(input);
        }

        int loop_count = n-k;
        while (loop_count--)
        {
            min = 1e8;
            vector<int>::iterator min_it;
            for (auto it= ara.begin(); it!=ara.end()-1; it++){
                if (*it+*(it+1)<min){
                    min = *it+*(it+1);
                    min_it = it;
                }
            }
            *min_it = min;
            ara.erase(min_it+1);
        }

        cout << "Case " << cases << ": " << min << endl;
        for (auto it= ara.begin(); it!=ara.end(); it++)
            cout << *it << endl;
    }
    return 0;
}