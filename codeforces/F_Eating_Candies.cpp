#include <bits/stdc++.h>
using namespace std;

// #define int long long int
#define double long double
#define print(str) cout << str << endl
#define loop(n) for (int i=0; i<n; i++)

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;
	return (*x - *y);
}

int32_t main()
{
    int test_cases;
    cin >> test_cases;
    for (int cases=1; cases<=test_cases; cases++)
    {
        int n, sum=0, in, out;
        cin >> n;
        int ara[n], sum_seq[n], sum_rev[n];
        loop(n){ 
            cin >> ara[i];
            sum += ara[i];
            sum_seq[i] = sum;
        }
        for (int i=n-1, j=0, sum=0; i>=0; i--, j++){
            sum += ara[i];
            sum_rev[j] = sum;
        }
        int max = sum_rev[n-1]/2;
        int max_index = lower_bound(sum_seq, sum_seq+n, max) - sum_seq;
        // cout << max_index << endl;

        int i, j;
        for (i=max_index; i>=0; i--){
            if (int* j_point = (int*)bsearch(sum_seq+i, sum_rev, n, sizeof(int), compare)){
                j = j_point - sum_rev;
                if (i+j<n-1){
                    print(i+1+j+1);
                    goto loop_end;
                }
            }
        }
        print(0);
        loop_end: ;
    }
    return 0;
}