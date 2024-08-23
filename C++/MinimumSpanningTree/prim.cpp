// coding: utf-8
// author: Poteamashusyu

#include <vector>
#include <set>
#include <queue>

using namespace std;

pair<long long, vector<set<int>>> prim(const vector<set<pair<long long, int>>>& adjacent) {
    pair<long long, vector<set<int>>> ret = {0LL, vector<set<int>>(adjacent.size())};
    vector<bool> connect(adjacent.size(), false);
    int remain = adjacent.size();
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> todo;

    todo.push({0LL, {0, 0}});

    while(remain > 0 && !todo.empty()) {
        long long w = todo.top().first;
        int from = todo.top().second.first, to = todo.top().second.second;
        todo.pop();

        if(connect[to]) continue;

        ret.first += w;
        if(from != to) {
            ret.second[from].insert(to);
            ret.second[to].insert(from);
        }
        connect[to] = true;
        remain--;

        for(const pair<long long, int> p : adjacent[to]) {
            long long sw = p.first; int sv = p.second;

            if(connect[sv]) continue;

            todo.push({sw, {to, sv}});
        }
    }

    if(remain == 0) {
        ret.first = -1LL;
    }

    return ret;
}