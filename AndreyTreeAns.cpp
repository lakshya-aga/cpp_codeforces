#include <iostream>
 
using namespace std;
 
struct DSU {
    vector<int> p, r;
    int comp;
    DSU(int n) : p(n), r(n) {
        iota(p.begin(), p.end(), 0);
        comp = n;
    }
    int find(int v) {
        return (p[v] == v) ? v : p[v] = find(p[v]);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        comp--;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> tin(n), tout(n), l0(n), r0(n);
        vector<int> lup(n), rup(n);
        int timer = 0;
        vector<int> ord;
        function<void(int, int)> dfs = [&](int v, int p) {
            l0[v] = r0[v] = v;
            tin[v] = timer++;
            ord.push_back(v);
            for (int u : g[v]) {
                if (u == p) continue;
                dfs(u, v);
                l0[v] = min(l0[v], l0[u]);
                r0[v] = max(r0[v], r0[u]);
            }
            tout[v] = timer - 1;
        };
        dfs(0, 0);
        function<bool(int, int)> ancestor = [&](int v, int u) {
            return tin[v] <= tin[u] && tin[u] <= tout[v];
        };
        vector<int> pref_min_ord(n + 1, n), suf_min_ord(n + 1, n);
        vector<int> pref_max_ord(n + 1, -1), suf_max_ord(n + 1, -1);
        for (int i = 0; i < n; i++) {
            pref_min_ord[i + 1] = min(pref_min_ord[i], ord[i]);
            pref_max_ord[i + 1] = max(pref_max_ord[i], ord[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            suf_min_ord[i] = min(suf_min_ord[i + 1], ord[i]);
            suf_max_ord[i] = max(suf_max_ord[i + 1], ord[i]);
        }
        for (int id = (int)ord.size() - 1; id >= 0; id--) {
            int v = ord[id];
            lup[v] = min(pref_min_ord[tin[v]], suf_min_ord[tout[v] + 1]);
            rup[v] = max(pref_max_ord[tin[v]], suf_max_ord[tout[v] + 1]);
        }
        vector<vector<pair<int, int>>> ans(n);
        vector<int> weight(n);
        function<void(int, int)> dfs2 = [&](int v, int p) {
            vector<int> all_id, all_tin;
            int idpar = -1;
            for (int id = 0; id < g[v].size(); id++) {
                int u = g[v][id];
                if (u != p) {
                    dfs2(u, v);
                    all_id.push_back(id);
                    all_tin.push_back(tin[u]);
                } else {
                    idpar = id;
                }
            }
            function<int(int)> get_subtree = [&](int u) {
                if (!ancestor(v, u)) return idpar;
                return all_id[upper_bound(all_tin.begin(), all_tin.end(), tin[u]) - all_tin.begin() - 1];
            };
            DSU dsu(g[v].size());
            function<void(int, int)> try_add = [&](int x, int y) {
                if (x == -1 || y == n || x == v || y == v) return;
                if (dsu.join(get_subtree(x), get_subtree(y))) {
                    ans[v].push_back({x, y});
                    weight[v] += abs(x - y);
                }
            };
            for (int u : g[v]) {
                if (u != p) {
                    try_add(l0[u] - 1, l0[u]);
                    try_add(r0[u], r0[u] + 1);
                } else {
                    try_add(lup[v] - 1, lup[v]);
                    try_add(rup[v], rup[v] + 1);
                }
            }
            if (dsu.comp != 1) {
                try_add(v - 1, v + 1);
            }
            assert(dsu.comp == 1);
        };
        dfs2(0, 0);
        for (int i = 0; i < n; i++) {
            cout << weight[i] << " " << ans[i].size() << "\n";
            for (auto [a, b] : ans[i]) {
                cout << a + 1 << " " << b + 1 << "\n";
            }
            cout << "\n";
        }
    }
}