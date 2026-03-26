// 28-06-2023 23:50
#include <iostream>
#include <vector>
using namespace std;

#define int long long
typedef vector<vector<int>> matrix;

int32_t main(void)
{
    int n, m;
    cin >> n;

    matrix adj_matrix(n + 1, vector<int>(n + 1));
    // inputting the edges
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> adj_matrix[i][j];

    vector<int> v(n);
    #define scanx(array) { for (auto &x: array) cin >> x; }
    scanx(v);

    vector<int> ans(n, 0);
    for (int index = n-1; index >= 0; --index)
    {
        int k = v[index];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);


        for (int p = index; p < n; p++) {
            for (int q = index; q < n; q++){
                int i = v[p], j = v[q];
                ans[index] += adj_matrix[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}