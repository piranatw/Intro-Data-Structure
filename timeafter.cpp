#include <iostream>
#include <string>
using namespace std;
int main(){
    string hh,mm;
    cin >> hh >> mm;
    int h = stoi(hh),m = stoi(mm);
    int min,hour;
    cin >> min;
    hour = min / 60;
    min = min%60;
    h = h + hour;
    m = min + m;
    if(m >= 60){
        h = h + 1;
        m -= 60;
    }
    if(h >= 24){
        h-=24;
    }
    if(h < 10){
        cout << "0" << h << " ";
        if(m < 10)
            cout << "0" << m;
        else cout << m;
    }
    else{
        cout << h <<  " ";
        if(m < 10)
            cout << "0" << m;
        else cout << m;
    }
}