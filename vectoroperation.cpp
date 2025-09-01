#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int q;
    string opr;
    cin >> q;
    vector <int> ans;
    while(q--){
        cin >> opr;
        if(opr == "pb"){
            int num;
            cin >> num;
            ans.push_back(num);
        }
        else if(opr == "sa"){
            sort(ans.begin(),ans.end());
        }
        else if(opr == "sd"){
            sort(ans.begin(),ans.end(),greater<int>());
        }
        else if(opr == "r"){
            reverse(ans.begin(),ans.end());
        }
        else{
            int num;
            cin >> num;
            ans.erase(ans.begin() + num);
        }
    }
    for(auto x : ans){
        cout << x <<  " ";
    }
    return 0;
}