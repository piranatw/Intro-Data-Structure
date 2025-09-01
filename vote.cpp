#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    unordered_map<string,int> candidate;
    for(int i = 1 ;i <= n ;i++){
        string name;
        cin >> name;
        candidate[name] += 1;
    }
    vector <int> score;
    for(auto x : candidate){
        if(x.second > 0) score.push_back(x.second);
    }
    if(k > score.size() - 1){
        int mn = 1e9;
        for(auto x : candidate){
            mn = min(mn,x.second);
        }
        cout << mn << endl;
        return 0;
    }
    sort(score.begin(),score.end(),greater<int>());
    cout << score[k-1] << endl;
    return 0;
}