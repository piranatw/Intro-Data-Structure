#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector <ll> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int val;
        cin >> val;
        v.push_back(val);
    }
    unordered_map <ll,ll> mp;
    map <ll,set<int>> freq;
    while(m--){
        int opr;
        cin >> opr;
        if(opr == 1){
            int code,val;
            cin >> code >> val;
            if(code > n) continue;
            ll old = mp[code];
            ll now = old + val;
            mp[code] = now;
            if(old > 0){
                freq[old].erase(code);
                if(freq[old].empty())   freq.erase(old);
            }
            freq[now].insert(code);
        }
        else{
            ll val;
            cin >> val;
            auto it = freq.lower_bound(val);
            if(it == freq.begin()){
                cout << "NONE\n";
            }
            else{
                it--;
                cout << *it->second.rbegin() << '\n'; 
            }
        }
    }
}