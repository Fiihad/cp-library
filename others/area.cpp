#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        int n;
        cin >> n;
        vector<int> vect;
        set<pair<int, int>> s;

        for (int i=0; i<n; i++){
            int input;
            cin >> input;
            vect.push_back(input);
            s.insert(make_pair(input, i));
        }
        int count = 0;
        auto it=s.begin();
        for (int i=0; i<n; i++, it++)
        {
            if (vect[i] != (*it).first)
            {
                int temp = vect[i];
                vect[i] = (*it).first;
                vect[(*it).second] = temp;
                count++;
            }
        }

        cout << "Case " << cases << ": " << count << endl;
    }
    return 0;
}