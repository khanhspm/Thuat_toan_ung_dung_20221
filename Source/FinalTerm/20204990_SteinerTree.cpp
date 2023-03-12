/*Một mạng truyền thông G gồm N máy chủ kết nối với nhau bởi M đường truyền (2 chiều). Giữa 2 máy chủ i và j
có thể có đường truyền hoặc không. trong trường hơpk giữa hai máy chủ i và j có thể có đường truyền thì c(i,j) 
là chi phí trên đường truyền này.
Một công ty cần tính toán phương án thuê 1 số đường truyền nào đó của mạng G để kết nối liên thông với 1 máy chủ tập R
(R là tập con của N). hẫy tính toán chi phí thuê đường truyền với chi ohis nhỏ nhất
input: - 2 số nguyên dương N và M
       - dòng 2 đến M : mỗi dòng ghi 3 số nguyên dương i, j, w : có đường truyền giữa i và j với chi phí thuê w (w = c(i,j))
       - dòng M+2: số nguyên dương K
       - dòng M+3: ghi K số nguyên dương đôi một khác nhau là chỉ sóo của các máy chủ trong R.    */


#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int n, m, k;
vector<pair<int, int>> adj[100005];
bool inR[100005];

int prim() {
    vector<int> dist(n+1, INF);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        if (dist[u] != d) continue;

        for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = it->first;
            int w = it->second;
            if (inR[v] && w < dist[v]) {
                dist[v] = w;
                pq.push({dist[v], v});
        }
}

    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (inR[i]) ans += dist[i];
    }

    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        inR[x] = true;
    }

    int ans = prim();
    cout << ans << endl;

    return 0;
}
