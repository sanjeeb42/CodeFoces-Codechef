#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll max(ll a, ll b)
{
    return a >= b ? a : b;
}
void solve()
{

    int x;
    cin >> x;
    vector<int> arr(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    vector<bool> visited(3, false);

    int curr_key = x;
    int times = 3;
    while (times--)
    {
        visited[curr_key - 1] = true;
        curr_key = arr[curr_key - 1];
        if (curr_key <= 0)
        {
            break;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (visited[i] == false)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

void solve2()
{
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> psum(n, 0);
    vector<ll> ssum(n, 0);

    for (int i = 1; i < n; i++)
    {
        psum[i] = max(arr[i - 1] - arr[i], 0);
        psum[i] = psum[i - 1] + psum[i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        ssum[i] = max(arr[i + 1] - arr[i], 0);
        ssum[i] = ssum[i] + ssum[i + 1];
    }

    for (int i = 0; i < q; i++)
    {
        ll left, right;
        cin >> left >> right;
        if (left < right)
        {
            cout << psum[right - 1] - psum[left - 1] << endl;
        }
        else
            cout << ssum[right - 1] - ssum[left - 1] << endl;
    }
}

void solve3()
{
    string s;
    cin >> s;
    int n = s.length();
    if (n % 2 != 0)
    {
        cout << "NO" << endl;
        return;
    }
    int open = 0, close = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            open++;
        else if (s[i] == ')')
            close++;
    }

    int ques = n - (open + close);
    // cout << ques << " ";
    if (ques == 0 or ques == 1 or (ques == 2 &&n == ques))
    {
        cout << "YES" << endl;
        return;
    }

    if (ques == n)
    {
        cout << "NO" << endl;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve3();
    }

    return 0;
}
