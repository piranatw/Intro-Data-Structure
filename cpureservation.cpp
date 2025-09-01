#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Interval
{
    int start, end;
    Interval(int s, int e) : start(s), end(e) {}
};

struct Compare
{
    bool operator()(const Interval &a, const Interval &b) const
    {
        return a.start < b.start;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Interval> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    set<Interval, Compare> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int a = v[i].start, b = v[i].end;
        Interval current(a, b);
        auto it = s.lower_bound(current);
        bool overlap = false;

        // Check the next interval
        if (it != s.end())
        {
            if (it->start <= b)
            {
                overlap = true;
            }
        }
        // Check the previous interval
        if (!overlap && it != s.begin())
        {
            it--;
            if (it->end >= a)
            {
                overlap = true;
            }
        }
        if (!overlap)
        {
            s.insert(current);
            ans.push_back(i + 1);
        }
    }
     for (int i = 0; i < ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}