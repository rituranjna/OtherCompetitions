#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, m, x[5000], y[5000], l[5000];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n + m; i++)
        cin >> x[i] >> y[i] >> l[i];
    int maxi = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int q = 0;
            q = max(min(min(x[i] - x[n + j], x[n + j] + l[n + j] - x[i]), min(y[n + j] - y[i], y[i] + l[i] - y[n + j])), 0);
            maxi = max(q, maxi);
        }
    cout << maxi;
    return 0;
}
