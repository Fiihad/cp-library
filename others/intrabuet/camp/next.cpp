#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int n, k;
    cin >> n >> k;
    int count = k;

    int ara[n];
    for (int i=0; i<n; i++){
        cin >> ara[i];
    }
    if (ara[k-1]) for (int i=k; ara[i]==ara[k-1] && i<n; i++) count++;
    else for (int i=k-1; !(ara[i]) && i>=0; i--) count--;

    cout << count;

    return 0;
}