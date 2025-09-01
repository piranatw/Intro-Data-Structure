#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;
int main()
{
    cout << fixed << setprecision(2);
    int n;
    cin >> n;
    map<string,pair<int,int>> subject;
    map<string,pair<int,int>> teacher;
    for(int i=0 ;i< n;i ++){
        string code,name;
        int score;
        cin >> code >> name >> score;
        subject[code].first += score;
        subject[code].second +=  1;
        teacher[name].first += score;
        teacher[name].second += 1;
    }
    for(auto x : subject){
        double avg = (x.second.first + 0.0) / x.second.second;
        cout << x.first << ' ' << avg << endl;
    }

    for(auto x : teacher){
        double avg = (x.second.first + 0.0) / x.second.second;
        cout << x.first << ' ' << avg << endl;
    }
    
    return 0;
}