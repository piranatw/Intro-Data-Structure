#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int main()
{
    ll r, c, q, k;
    cin >> r >> c >> k;
    vector<ll> v(k);
    for (int i = 0; i < k; i++)
    {
        ll n, m;
        cin >> n >> m;
        v[i] = (n - 1) * c + (m - 1);
    }
    sort(v.begin(),v.end());
    cin >> q;
    while(q--){
        ll n,m,ans,start;
        cin >> n >> m;
        start = (n - 1) * c + (m - 1);
        auto it = lower_bound(v.begin(),v.end(),start);
        if(*it == start && it != v.end()){
            ans = 0;
        }
        else if(it != v.end()){
            ans = *it - start;
        }
        else{
            ans = r*c - start + v[0];
        }
        cout << ans << endl;
    }
}
