// 20-10-2022 15:50
#include <bits/stdc++.h>
using namespace std;

long long sum_of_factors[1000000+5];
int main (void)
{
    for (int i=1; i<=1e6; i++){
        for (int j=i+i; j<=1e6; j+=i) sum_of_factors[j] += i;
    }
    // for (int i=1; i<26; i++) cout << i << ": " << sum_of_factors[i] << endl;

    int count = 0;
    for (int i=1; i<=1e6; i++){
        long long sum = sum_of_factors[i];
        if (sum<=1e6 && sum>i && sum_of_factors[sum]==i) count++, cout << i << ' ' << sum << endl;
    }

    cout << "Total count: " << count << endl;
    return 0;
}