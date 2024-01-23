// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool solve(int n, unordered_map<int, vector<int>> &mp, vector<int> &ans, vector<int> &inDegree)
{

    int count = 0; // this should ultimately be equal to n
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        { // start with the one who doesnt have any pre req
            q.push(i);
            ans.push_back(i);
        }
    }

    unordered_set<int> st;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        if (mp.find(node) != mp.end())
            for (int v : mp[node])
            {
                inDegree[v]--;

                if (inDegree[v] == 0)
                    ans.push_back(v);

                if (st.find(v) == st.end())
                {
                    q.push(v);
                }
                st.insert(v);
            }
    }

    if (count == n)
        return true;

    return false;
}

vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites)
{
    unordered_map<int, vector<int>> mp;
    vector<int> inDegree(n, 0);

    for (vector<int> row : prerequisites)
    {
        int a = row[0];
        int b = row[1];

        inDegree[a]++;
        mp[b].push_back(a);
    }

    vector<int> ans;

    bool status = solve(n, mp, ans, inDegree);

    if (status)
        return ans;

    return {};
}

int main()
{
    vector<vector<int>> nums{{3, 10}, {11, 12}, {11, 13}, {2, 9}, {7, 8}, {0, 6}};
    vi ans = findOrder(17, 6, nums);

    for (int i : ans)
        cout << i << " ";
    cout << endl;
}