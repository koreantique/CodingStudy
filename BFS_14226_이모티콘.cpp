#include <iostream>
#include <tuple>
#include <queue>


using namespace std;
int d[1001][1001];
int check[1001][1001] = {0,};
int main() {
    int n;
    cin >> n;

    queue<pair<int,int>> q;
    q.push(make_pair(1,0));
    check[1][0] = 1;
    while (!q.empty()) {
        int s, c;
        tie(s, c) = q.front();
        q.pop();
        if (check[s][s] == 0) { //복사한 적이 없으면,
            check[s][s] = check[s][c] + 1; //횟수를 1 증가시키고 (횟수 확인 위해)
            q.push(make_pair(s,s)); //복사하는 연산을 큐에 집어넣는다.
        }
        if (s+c <= n && check[s+c][c] == 0) { //붙여넣기 한 적이 없다면
            check[s+c][c] = check[s][c] + 1; //횟수를 1 증가시키고
            q.push(make_pair(s+c, c)); //붙여넣는 연산을 큐에 집어넣는다.
        }
        if (s-1 >= 0 && check[s-1][c] == 0) { //지우기 연산을 한 적이 없다면
            check[s-1][c] = check[s][c] + 1; //횟수를 1 증가시키고
            q.push(make_pair(s-1, c)); //지우는 연산을 큐에 집어넣는다.
        }
    }
    int ans = -1;
    for (int i=0; i<=n; i++) {
        if (check[n][i] != 0) {
            if (ans == -1 || ans > check[n][i]) {
                ans = check[n][i];
            }
        }
    }
    cout << ans-1 << '\n';
    return 0;
}