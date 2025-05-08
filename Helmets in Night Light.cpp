#include <bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(0);
#define int long long
#define yes cout << "yes\n"
#define no cout << "no\n"
#define neg1 cout << "-1\n"
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
        int n, p; 
        cin >> n >> p;
        vi a(n), b(n);
        input(a); input(b);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({b[i], a[i]});
        }

        int min_cost = p;
        int already_shared = 1;

        int flag = 0;
        while (!pq.empty()) {
            int cost = pq.top().first;
            int sharable = pq.top().second;
            pq.pop();
            
            if (cost >= p) {
                flag = 1;
                break;
            }

            if (sharable + already_shared >= n) {
                min_cost += (n - already_shared) * cost;
                break;
            } else {
                min_cost += sharable * cost;
                already_shared += sharable;
            }
        }

        if (flag) {
            int left = n - already_shared;
            min_cost += left * p;
            cout << min_cost << endl;
        }
        else cout << min_cost << endl;
    }
}
