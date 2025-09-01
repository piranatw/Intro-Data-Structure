#include <map>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> word;
    for(int i= 1;i<=n;i++){
        string name;
        cin >> name;
        word[name]++;
    }
    int mx = -1e9;
    string ans;
    for(auto x : word){
        if(mx <= x.second){
            mx = x.second;
            ans = x.first;
        }
    }
    cout << ans << ' ' << mx << endl;
    return 0;
}