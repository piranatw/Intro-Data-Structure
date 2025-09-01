#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int a[10010];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0;i< n;i ++) {
        cin >> a[i];
    }
    sort(a,a + n);
    for(int i = 0;i< m;i++){
        int target;
        cin >> target;
        int l = 0,r = n - 1;
        bool found = false;
        while(l<r){
            long long sum = (long long)(a[l] + a[r]);
            if(sum == target){
                found = 1;
                break;
            }
            else if(sum < target){
                l++;
            }
            else{
                r--;
            }
        }
        cout << (found ? "YES\n": "NO\n");
    }
}