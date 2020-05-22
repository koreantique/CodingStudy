#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int d[101][101] = {0,};
int c[101][101] = {0,};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

void bfs(int x, int y, int h, int cnt){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    c[x][y] = cnt;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                if(d[nx][ny] > h && c[nx][ny] == 0){
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

    int h = 0; //높이
    int cnt = 0;
    int max = 0;

    while(1){
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j] > h && c[i][j] == 0) {
                    bfs(i,j,h,++cnt);
                }
            }
        }
        if(max < cnt) max = cnt;
        cnt = 0;
        memset(c, 0, sizeof(c));
        h++;
        if(h > 101) break;
    }



    cout << max << endl;
    
    


}