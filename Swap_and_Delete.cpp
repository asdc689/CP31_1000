#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(0);
#define int long long
#define yes cout << "yes\n"
#define no cout << "no\n"
#define m1 cout << "-1\n"
#define endl "\n"
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pb push_back
#define all(v) v.begin(), v.end()
#define sum(v) accumulate(all(v), 0)
#define minEL(v) *min_element(all(v))
#define maxEL(v) *max_element(all(v))
#define input(v) for (auto &i : v) cin >> i
#define print(v) for (auto &i : v) cout << i << " "

int floor_val(int a, int b) {
    return min(a / b, (a + (a < 0 ? -1 : 1) * (b - 1)) / b);
}

int ceil_val(int a, int b) {
    return max(a / b, (a + (a < 0 ? -1 : 1) * (b - 1)) / b);
}

int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}

signed main() {
    fastio();
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int cnt1 = 0, cnt0 = 0;
        for (char c : s) {
            if (c == '1') cnt1++;
            else cnt0++;
        }
        if (cnt1 == cnt0) cout << 0 << endl;
        else {
            for (char c : s) {
                if (c == '1') {
                    if (cnt0) cnt0--;
                    else break;
                } else {
                    if (cnt1) cnt1--;
                    else break;
                }
            }
            if (cnt1) cout << cnt1 << endl;
            else cout << cnt0 << endl;
        }
    }
}
