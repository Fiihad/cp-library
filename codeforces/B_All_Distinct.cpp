#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n, x, count = 0;
        cin >> n;
        set<int> input;
        while(n--)
        {
            cin >> x;
            if (input.find(x) != input.end()) count++;
            input.insert(x);
        }
        int output = count%2? input.size()-1 : input.size();
        cout << output << endl;
        input.clear();
    }
    return 0;
}