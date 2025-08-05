#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <list>
using namespace std;

using Matrix = vector<vector<int>>;

list<Matrix> genmove(Matrix state)
{
    list<Matrix> nextStates;
    int a, b;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (state[i][j] == 0)
            {
                a = i;
                b = j;
            }

    if (a - 1 >= 0)
    {
        Matrix A1 = state;
        swap(A1[a][b], A1[a - 1][b]);
        nextStates.push_back(A1);
    }

    if (a + 1 < 3)
    {
        Matrix A2 = state;
        swap(A2[a][b], A2[a + 1][b]);
        nextStates.push_back(A2);
    }

    if (b - 1 >= 0)
    {
        Matrix A3 = state;
        swap(A3[a][b], A3[a][b - 1]);
        nextStates.push_back(A3);
    }

    if (b + 1 < 3)
    {
        Matrix A4 = state;
        swap(A4[a][b], A4[a][b + 1]);
        nextStates.push_back(A4);
    }

    return nextStates;
}

string matrixToString(Matrix mat)
{
    string s;
    for (auto row : mat)
        for (int val : row)
            s += to_string(val);
    return s;
}

void bfs(Matrix prob, Matrix sol)
{
    queue<Matrix> q;
    unordered_set<string> closed;

    q.push(prob);
    closed.insert(matrixToString(prob));

    while (!q.empty())
    {
        Matrix A = q.front();
        q.pop();

        if (A == sol)
        {
            cout << "Success!" << endl;
            return;
        }

        list<Matrix> states = genmove(A);
        for (auto state : states)
        {
            string str = matrixToString(state);
            if (closed.find(str) == closed.end())
            {
                closed.insert(str);
                q.push(state);
            }
        }
    }

    cout << "Failed!" << endl;
}

int main()
{
    Matrix prob = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}};

    Matrix sol = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}};

    bfs(prob, sol);

    return 0;
}

