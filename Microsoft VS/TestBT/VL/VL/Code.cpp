#include <iostream>
using namespace std;
const int N = 1001;
int a[N][N], f[N][N], h[N][N], n, k;
void doc()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            h[i][j] = 0;

    h[1][1] = a[1][1];
    for (int j = 2; j <= n; j++)
        h[1][j] = a[1][j] + h[1][j - 1];

    for (int i = 2; i <= n; i++)
        h[i][1] = a[i][1] + h[i - 1][1];

    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            h[i][j] = a[i][j] + h[i - 1][j] + h[i][j - 1] - h[i - 1][j - 1];
}
int tong(int i, int j)
{
    return h[i + k - 1][j + k - 1] - h[i - 1][j + k - 1] - h[i + k - 1][j - 1] + h[i - 1][j - 1];
}
void xuly()
{
    int res = 0;
    for (int i = 1; i <= n - k + 1; i++)
        for (int j = 1; j <= n - k + 1; j++)
            f[i][j] = tong(i, j), res = max(res, f[i][j]);
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    doc();
    xuly();
	system("pause");
    return 0;
}