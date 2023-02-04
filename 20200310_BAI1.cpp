#include <bits/stdc++.h>
using namespace std;
int n, k, A, B, ans;
int arr[100007];
int main()
{
    cin >> n >> k >> A >> B;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        p[i + 1] = p[i] + arr[i];
    }
    for (int i = k; i <= n; i++)
    {
        if (p[i] - p[i - k] >= A && p[i] - p[i - k] <= B)
            ans++;
    }
    cout << ans;
}
