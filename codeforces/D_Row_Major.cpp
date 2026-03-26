/*
        আমার অমনোযোগী ক্লাসরুম... আমার মগজে নষ্ট ধুম...
        আমার বাহিরে বুদ্ধ, ভেতরে হিটলার... লাশের মোড়কে ঘুম :)
*/

#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define fast ios_base::sync_with_stdio(0); cin.tie(0);  // fast IO! but only when online_judge
#define debug 0
#else
#define fast ;
#define debug 1
#endif
// for debugging
#define bug(...) if (debug) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names+1, ',');
    cout.write (names, comma-names) << " : " << arg1 << " | "; __f (comma+1, args...);
}

// some typedefs for my convenience
#define int long long int
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
// some speedup macros
#define gap ' '
#define endl '\n'
#define print(str) cout << str << endl
#define YES print("YES")
#define NO print("NO")
#define loop(i, begin, end) for(__typeof(end)i=begin-(begin>end); i!=end-(begin>end); i+=1-2*(begin>end))
#define all(v) v.begin(), v.end()

int N = 1e7;
vector<bool> sieve(N+1, true);
vector<int> greatest_prime_factor(N+1), lowest_prime_factor(N+1, 0);
vector<int> primes;

void calculate_sieve()
{
    for (int i = 2; i <= N; i++)
        if (sieve[i]){
            greatest_prime_factor[i] = lowest_prime_factor[i] = i;
            for (int j = i*i; j <= N; j += i){
                sieve[j] = false;

                greatest_prime_factor[j] = i;
                if (!lowest_prime_factor[j]) lowest_prime_factor[j] = i;
            }
        }
    for (int i = 2; i <= N; i++)
        if (sieve[i]) primes.push_back(i);
}

vector<int> get_prime_factors(int n)
{
    vector<int> prime_factors, distinct_prime_factors;
    while (n > 1){
        int factor = greatest_prime_factor[n];
        distinct_prime_factors.push_back(factor);

        while (!(n % factor)){
            prime_factors.push_back(factor);
            n /= factor;
        }
    }
    return prime_factors;
}
// When n is larger than 1e7 (In that case N is enough to be sqrt(n))
vector<long long> get_prime_factors_iterative(long long n)
{
    vector<long long> prime_factors, distinct_prime_factors;
    for (int i=0; primes[i]*primes[i] <= n && i < primes.size(); i++){
        if (!(n % primes[i])) distinct_prime_factors.push_back(primes[i]);
        while (!(n % primes[i])){
            prime_factors.push_back(primes[i]);
            n /= primes[i];
        }
    }
    if (n != 1) prime_factors.push_back(n), distinct_prime_factors.push_back(n);
    return prime_factors;
}


void solve(int cases);
int32_t main()
{
    fast
    // calculate_sieve();
    int total_cases = 1;
    cin >> total_cases;
    loop(cases, 1, total_cases+1) solve(cases);
    return 0;
}

// SOLVE STARTS HERE

void solve(int cases)
{
    int n, q, out=0, sum=0, flag=0, maxi=LLONG_MIN, mini=LLONG_MAX;
    int in;
    cin >> n;

    loop(i,2,26){
        if (n % i){
            flag = i;
            break;
        }
    }

    char a = 'a';
    string s;
    loop(i,0,26) s.push_back(a++);

    loop(i,0,n){
        cout << s[i%flag];
    }
    cout << endl;
}

/*
        Fihad arRahman
        hellofihad@gmail.com
        11-07-2023 22:35
*/