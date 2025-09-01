#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> a(n),b(n),d(n);
    for(int i = 0;i < n;i++)    cin >> a[i];
    for(int j = 0; j < n; j++)  cin >> b[j];
    for(int i = 0;i < n;i++)    d[i] = a[i] - b[i];
    sort(d.begin(),d.end());
    int ans = 0;
    for(int i = 0; i < n;i++){
        int l = -d[i] + 1;
        int idx = lower_bound(d.begin() + i + 1,d.end(),l) - d.begin();
        ans += (n - idx);
    }
    cout << '\n' << ans << '\n';
    return 0;
}
// 0 2 -3 2