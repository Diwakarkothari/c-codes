#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    vector<long long> ans;
    queue<long long int> q;

    for (long long int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            q.push(A[i]);
    }

    if (q.size() > 0)
        ans.push_back(q.front());
    else
        ans.push_back(0);

    for (long long int i = K; i < N; i++)
    {
        // jata hua element negative hua ho to apan usko queue  meinse pop karenge
        if (!q.empty() && q.front() == A[i - K])
            q.pop();

        if (A[i] < 0)
        {
            q.push(A[i]);
        }
        if (q.size() > 0)
            ans.push_back(q.front());
        else
            ans.push_back(0);
    }
    return ans;
}