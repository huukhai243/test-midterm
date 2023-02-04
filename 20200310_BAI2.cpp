#include <bits/stdc++.h>
using namespace std;
multiset<int> arr;
int n, temp;
string query;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.insert(temp);
    }
    while (true)
    {
        cin >> query;
        if (query == "*")
            break;
        if (query == "insert") 
        {
            cin >> temp;
            arr.insert(temp);
        }
        else if (query == "delete-max") 
        {
            cout << *--arr.end() << endl;
            arr.erase(--arr.end());
        }
        else return 0;
    }
}
