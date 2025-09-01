#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    vector<int> v(n);
    multiset<int> low, high;
    vector<int> medians;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (n == w)
    {
        cout << v[n / 2] << '\n';
        return 0;
    }
    for (int i = 0; i <= w; i++)
        low.insert(v[i]);
    while (low.size() > (w + 1) / 2)
    {
        auto it = prev(low.end());
        high.insert(*it);
        low.erase(it);
    }
    medians.push_back(*prev(low.end()));
    for (int i = w + 1; i < n; i++)
    {
        int out = v[i - w - 1];
        int in = v[i];
        if (low.empty() || in <= *prev(low.end()))
        {
            low.insert(in);
        }
        else
        {
            high.insert(in);
        }
        if (low.find(out) != low.end())
        {
            low.erase(low.find(out));
        }
        else if (high.find(out) != high.end())
        {
            high.erase(high.find(out));
        }
        while (low.size() > (w + 1) / 2)
        {
            auto it = prev(low.end());
            high.insert(*it);
            low.erase(it);
        }
        while (low.size() < (w + 1) / 2)
        {
            auto it = high.begin();
            low.insert(*it);
            high.erase(it);
        }

        medians.push_back(*prev(low.end()));
    }
    for (auto x : medians)
    {
        cout << x << ' ';
    }
    return 0;
}