#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char d[101][101];
int c[101][101] = {0,};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n;

void bfs(int x, int y, char alpha, int cnt){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                if(d[nx][ny] == alpha && c[nx][ny] == 0){
                    q.push(make_pair(nx,ny));
                    c[nx][ny] = cnt;
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> d[i][j];
        }
    }

    int cnt = 0;
    int cnt_2 = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(c[i][j] == 0) bfs(i,j,d[i][j], ++cnt);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(d[i][j] == 'R') d[i][j] = 'G';
        }
    }

    memset(c, 0, sizeof(c));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(c[i][j] == 0) bfs(i,j,d[i][j], ++cnt_2);
        }
    }

    cout << cnt << " " << cnt_2 << endl;



}