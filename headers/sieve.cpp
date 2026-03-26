// 01-05-2023 17:33
#include <bits/stdc++.h>
using namespace std;

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

int main (void)
{
    

    return 0;
}