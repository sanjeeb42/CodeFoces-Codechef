#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool attack(int x, int y, int dx, int dy, int d)
{
    float x1 = (1.0 * dx - 1.0 * x);
    x1 *= x1;

    float y1 = (1.0 * dy - 1.0 * y);
    y1 *= y1;

    float distance = sqrt(y1 + x1);
    if (distance <= d)
    {
        return true;
    }
    return false;
}
void solve2()
{
    int n, m;
    cin >> n >> m;

    int dx, dy;
    cin >> dx >> dy;
    int d;
    cin >> d;

    int ans = n - 1 + m - 1;

    // Check if Posssible to reach or not
    if (attack(n, m, dx, dy, d) or attack(1, 1, dx, dy, d))
    {
        // cout<<"Entered"<<endl;
        ans = -1;
    }

    int up = abs(dx - 1) <= d;
    int down = abs(dx - n) <= d;
    int left = abs(dy - 1) <= d;
    int right = abs(dy - m) <= d;

    // cout << up << " " << down << " " << left << " " << right << endl;

    int cnt = up + down + left + right;

    if ((up && left) or (right && down) or (up && down) or (left && right))
    {
        ans = -1;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int cnt = 0;
        for (auto it : nums)
        {
            if (it == 1)
                cnt++;
        }

        int cnt_now = 0;
        int i = 0, j = 0;
        int k = cnt;
        int ans = INT_MAX;

        while (j < n)
        {
            if (nums[j] == 1)
                cnt_now++;

            if (j > k)
            {
                ans = min(ans, cnt - cnt_now);
                if (nums[i] == 1)
                {
                    cnt_now--;
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};