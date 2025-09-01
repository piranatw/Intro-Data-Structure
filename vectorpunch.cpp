#include <iostream>
#include <vector>
using namespace std;
vector<string> punch(vector<string> &v, vector<string>::iterator it, int k)
{
    vector<string> result;
    if (k <= 0 || it == v.end())
        return result;
    for(int i = 0;i < v.size();i++){

        if(i < int(it - v.begin()) - k || i > int(it - v.begin()) + k)  result.push_back(v[i]);

    }
    return result;
}
int main()
{
    int n, j, k;    
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result)
    {
        cout << x << endl;
    }
}