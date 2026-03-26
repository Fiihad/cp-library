#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n, n2, m, input;
        cin >> n >> m;
        vector<pair<int, long long>> first, second;
        while (n--){
            cin >> input;
            if (input%m){
                if (!first.empty()){
                    if ((*(first.end()-1)).first==input){
                        first.push_back(make_pair(input, (*(first.end()-1)).second+1));
                        first.erase((first.end()-2));
                    }
                    else first.push_back(make_pair(input, 1));
                }
                else first.push_back(make_pair(input, 1));
            }
            else{
                long long count = 0;
                for (; input%m==0; input/=m) count++;
                count = pow(m,count);
                if (!first.empty()){
                    if ((*(first.end()-1)).first==input){
                        count+=(*(first.end()-1)).second;
                        first.erase((first.end()-1));
                    }
                }
                first.push_back(make_pair(input, count));
            }
        }

        cin >> n2;
        while (n2--){
            cin >> input;
            if (input%m){
                if (!second.empty()){
                    if ((*(second.end()-1)).first==input){
                        second.push_back(make_pair(input, (*(second.end()-1)).second+1));
                        second.erase((second.end()-2));
                    }
                    else second.push_back(make_pair(input, 1));
                }
                else second.push_back(make_pair(input, 1));
            }
            else{
                long long count = 0;
                for (; input%m==0; input/=m) count++;
                count = pow(m,count);
                if (!second.empty()){
                    if ((*(second.end()-1)).first==input){
                        count+=(*(second.end()-1)).second;
                        second.erase((second.end()-1));
                    }
                }
                second.push_back(make_pair(input, count));
            }
        }

        //  for (auto it=first.begin(); it!=first.end(); it++)
        //     cout << (*it).first << ',' << (*it).second << ' ';
        // cout << endl;
        // for (auto it=second.begin(); it!=second.end(); it++)
        //     cout << (*it).first << ',' << (*it).second << ' ';
        // cout << endl; 

        if (first == second) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}