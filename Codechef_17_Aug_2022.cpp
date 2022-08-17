#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int maxi = max(a, c);
    if (maxi <= b)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}

void solve2()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    string s;
    cin >> s;
    int ans = 1e7;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            ans = min(ans, arr[i]);
        }
    }

    cout << ans << endl;
}
void solve3()
{
    ll n;
    cin >> n;

    ll ans;
    cin >> ans;

    for (int i = 1; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        ans = __gcd(ans, tmp);
    }

    ll fans = ans * n;
    cout << fans << endl;
}

char change(char a)
{
    if (a == '1')
        return '0';
    else
        return '1';
}
void solve4()
{
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    int i = 0;
    int tmp = (n - k + 1);
    for (int i = 0; i <= n - k; i++)
    {
        if (tmp == 0)
        {
            break;
        }
        if (s[i] == '1')
        {
            for (int j = i; j < i + k; j++)
            {
                s[j] = change(s[j]);
            }
            tmp--;
        }

        //  cout << s << endl;
    }
    cout << s << endl;
}

void solve4_2()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    int tmp = (n - k + 1);

    bool comp = false;
    int cstart = -1, cend = -1;
    int i;
    for (i = 0; i < n - k; i++)
    {
        // if(s[i]==1)

        if (!tmp)
        {
            break;
        }
        if (i > cend)
        {
            comp = false;
            cstart = n, cend = n;
        }
        cout << comp << " " << cstart << " " << cend << endl;
        if (s[i] == '1' && comp == false)
        {
            s[i] = '0';
            // Start && end Included
            cstart = i + 1, cend = i + (k - 1);
            comp = true;
            tmp--;
        }
        else if (s[i] == '1' && comp == true)
        {
            s[i] = '0';
            // cstart = i + 1, cend = i + (k - 1);

            // cstart = i;
        }
        else if (s[i] == '0' && comp == true)
        {

            cstart = max(i + 1, cend), cend = i + (k - 1);
            tmp--;
            comp = false;
        }

        cout << s << endl;
    }

    cout << comp << " " << cstart << " " << cend << endl;

    if (comp)
    {
        for (int j = max(i, cstart); j <= min(cend, n - 1); j++)
        {
            s[j] == '0' ? s[j] = '1' : s[j] = '0';
        }
    }
    cout << s << endl;
}
bool checkmod(int x)
{
    if (x % 2 == 0)
        return true;
    else
        return false;
}
void solve5()
{
    ll row, col;
    cin >> row >> col;
    ll alice_moves, bob_moves;
    cin >> alice_moves >> bob_moves;
    ll path = (row + col);
    ll mycover = alice_moves + bob_moves;
    bool tmp = checkmod(path + alice_moves);
    bool t1 = mycover % 2;
    bool t2 = path % 2 ;
    if ((path+alice_moves)%2!=0)
    {
        if (mycover % 2 == 0)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        //   solve4();
        solve5();
    }
    return 0;
}
