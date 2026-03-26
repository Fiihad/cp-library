#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n, zero=0;
        cin >> n;
        vector<int> ara;
        set<int> s;
        for (int i=0; i<n; i++){
            int input;
            cin >> input;
            if (input || !zero){
                ara.push_back(input);
                s.insert(input);
                if (!input) zero=1;
            }
        }

        if (s.size()==1)
        {
            if (*s.begin() == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }
        if (ara.size() > 4){
            cout << "NO" << endl;
            continue;
        }

        n=ara.size();
        for (int i=0; i<n-2; i++)
            for (int j=i+1; j<n-1; j++)
                for (int k=j+1; k<n; k++){
                    for (int l=0; l<n; l++)
                        if (ara[i]+ara[j]+ara[k]==ara[l]) goto here;
                    cout << "NO" << endl;
                    goto loop_end;
                    here: ;
                }
        cout << "YES" << endl;
        loop_end: ;
    }
    return 0;
}