#include <iostream>
using namespace std;

int a[110][110];
int main(){
    int n,m;
    cin >> n >> m;
    int q;
    cin >> q;
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    while(q--){
        int r,c,rr,cc;
        cin >> r >> c >> rr >> cc;
        if(rr < r || cc < c){    
            cout << "INVALID" << endl;
            continue;
        }
        if(r > n || c > m) {
            cout << "OUTSIDE" << endl;
            continue;
        }

        int mx = -1e9;
        for(int i = r-1;i <= min(n,rr-1) ;i++){
            for(int j = c-1;j <= min(cc - 1,m);j++){
                mx = max(mx,a[i][j]);
            }
        }
        cout << mx << endl;
    }
    return 0;
}