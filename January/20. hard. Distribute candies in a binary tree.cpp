// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

struct Node
{
    int key;
    Node *left, *right;
};

class Solution
{
public:
    int solve(Node *root, int &moves)
    {

        if (root == NULL)
            return 0;

        int l = solve(root->left, moves);
        int r = solve(root->right, moves);

        moves += abs(l) + abs(r);

        return (l + r + root->key) - 1;
    }

    int distributeCandy(Node *root)
    {
        int moves = 0;

        solve(root, moves);

        return moves;
    }
};