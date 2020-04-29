#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[101][101];
int check[101][101] = {0,};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int cnt = 0;

void bfs(int x, int y, int cnt){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    check[x][y] = cnt;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(map[nx][ny] == 1 && check[nx][ny] == 0){
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = check[x][y]+1;
                }
            }
        }
        
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    bfs(0,0,++cnt);

    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << check[i][j];
        }
        cout << endl;
    }
    */
    
    cout << check[n-1][m-1] <<endl;
    
}

