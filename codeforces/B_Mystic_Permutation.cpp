#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    test_case:
    while (test_cases--)
    {
        int n;
        cin >> n;
        multiset<pair<int, int>> input;
        int output[n];

        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            input.insert({x, i});
        }

        for(int i=0; i<n; i++)
        {
            auto it = input.begin();
            if (input.size() == 1)
            {
                if (i==0){
                    cout << -1 << endl;
                    goto test_case;
                }
                else if ((*it).second == i) {
                    int temp;
                    temp = output[i-1];
                    output[i] = output[i-1];
                    output[i-1] = (*it).first;
                    break;
                }
            }
            if ((*it).second == i) it++;

            output[i] = (*it).first;
            input.erase(it);
        }

        for (int i=0; i<n; i++) cout << output[i] << ' ';
        cout << endl;
    }
    return 0;
}