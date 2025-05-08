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
        int n, k;
        cin >> n >> k;
        vi arr(n);
        input(arr);
        
        if (k != 4) {
            int flag = 0, rem = 0, diff = 100;
            for (int i : arr) {
                if (i % k == 0) {
                    flag = 1;
                    break;
                }
                rem = i % k;
                diff = min(diff, k - rem);
            }
            if (flag) cout << 0 << endl;
            else cout << diff << endl;
        } else {
            int flag = 0, evenCnt = 0;
            int rem = 0, diff = 100;
            for (int i : arr) {
                if (i % 4 == 0) {
                    flag = 1;
                    break;
                }
                else if (i % 2 == 0) evenCnt++;
                rem = i % k;
                diff = min(diff, k - rem);
            }
            if (flag || evenCnt >= 2) cout << 0 << endl;
            else if (evenCnt == 1 || diff == 1) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
}
