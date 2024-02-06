// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string solve(string x)
{
    int n = x.size();

    unordered_set<char> st;
    string ans;

    for (char i : x)
    {
        // the given character is found
        if (st.find(i) != st.end())
            continue;

        // occuring for the first time
        st.insert(i);

        ans.push_back(i);
    }

    return ans;
}

int main()
{
    string x; // geeksforgeeks
    cin >> x;

    cout << solve(x) << endl;
}