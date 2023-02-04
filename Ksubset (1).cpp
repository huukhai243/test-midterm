#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<vector<int>> result;
int n, k, m;
int arr[1000];
void ok(int k, int idx)
{
    if (idx == n)
        return;
    if (k == 1)
    {
        for (int i = idx; i < n; i++)
        {
            v.push_back(arr[i]);
            result.push_back(v);
            v.pop_back();
        }
    }
    for (int j = idx; j < n; j++)
    {
        v.push_back(arr[j]);
        ok(k - 1, j + 1);
        v.pop_back();
    }
}

int main()
{
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ok(k, 0);
    int ans = 0;
    for (int i = 0; i < result.size(); i++)
    {
        int temp = 0;
        for (auto j : result[i])
            temp += j;
        ans += temp == m;
    }
    cout << ans;
}