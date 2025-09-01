#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    map<long long,long long> father;
    for(int i = 1;i <= n ;i ++){
        long long f,s;
        cin >> f >> s;
        father[s] = f;
    }  
    while (m--){
        long long a,b;
        cin >> a >> b;
        if(a == b)  {
            cout << "NO\n";
            continue;
        }
        auto ita = father.find(a);
        auto itb = father.find(b);
        if(ita == father.end() || itb == father.end()){
            cout << "NO\n";
            continue;
        }
        auto itFA = father.find(ita->second);
        auto itFB = father.find(itb->second);

        if (itFA == father.end() || itFB == father.end()) {
            cout << "NO\n";
            continue;
        }

        if (itFA->second == itFB->second) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}