// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pr;

vii ans;
void print(vii ans)
{
    for (vector<int> row : ans)
    {
        for (int i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void solve(map<int, int> &mp)
{
    priority_queue<pr, vector<pr>, greater<pr>> pq;

    for (auto pair : mp)
    {
        // cout << pair.first << " " << pair.second << " ";
        pq.push({pair.second, pair.first});
    }

    vector<int> row;
    while (!pq.empty())
    {
        row.push_back(pq.top().second);
        pq.pop();
    }

    ans.push_back(row);
}

vector<vector<int>> kTop(vector<int> &arr, int N, int K)
{
    map<int, int> mp;

    for (int i : arr)
    {
        mp[i]++;
        solve(mp);
    }

    return ans;
}

int main()
{
    vi nums = {5, 2, 1, 3, 2};
    vii ans = kTop(nums, 5, 4);
    print(ans);
}