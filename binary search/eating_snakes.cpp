#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, q, a[100009], x, ans[100009];
vector < pair < ll, ll >> qr;

int main() {
    cin >> t;
    while (t--) {
        qr.clear();
        cin >> n >> q;
        for (int i = 1; i < n + 1; i++)
            cin >> a[i];
        for (int i = 0; i < q; i++) {
            cin >> x;
            qr.push_back(make_pair(x, i));
        }
        sort(a + 1, a + n + 1);
        sort(qr.begin(), qr.end());
        ll cur = 0;
        ll prev = 0, presum = 0;
        for (int i = 1;; i++) {
            ll fir = qr[cur].first;
            while (a[i] < fir && i < n + 1) {
                presum += (fir - a[i]);
                i++;
            }
            i--;
            while (presum > prev) {
                prev++;
                presum -= (fir - a[prev]);
            }
            ans[qr[cur].second] = n - prev;
            if (cur == q - 1)
                break;
            presum = presum + (i - prev) * (qr[cur + 1].first - fir);
            cur++;
        }
        for (int i = 0; i < q; i++)
            cout << ans[i] << "\n";
    }
}