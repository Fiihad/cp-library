#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
    vector<double> roots;

    double n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        roots.push_back(sqrt(i));

    for (int i = 0; i < n; i++)
        cout << roots[i] << endl;
    return 0;
}