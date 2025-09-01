#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    map<string,set<string>> mp;
    map<string,string> department;
    for(int i = 0 ;i< n;i++){
        string s,dept;
        cin >> s >> dept;
        mp[dept].insert(s);
        department[s] = dept;

    }
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            string name,dept;
            cin >> name >> dept;
            string tmp = department[name];
            department[name] = dept;
            mp[tmp].erase(name);
            mp[dept].insert(name);
        }
        else{
            string dept1,dept2;
            cin >> dept1 >> dept2;
            for(auto x : mp[dept1]){
                mp[dept2].insert(x);
                department[x] = dept2;
            }
            mp[dept1].clear();
            mp.erase(dept1);
        }
    }
    for(auto x:mp){
        cout << x.first << ": ";
        for(auto v : x.second){
            cout << v << ' ';
        }
        cout << '\n';
    }
    return 0;
}