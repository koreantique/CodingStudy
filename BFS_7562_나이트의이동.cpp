#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int d[301][301];
int c[301][301];
int dx[] = {-2,-1,1,2,-2,-1,1,2};
int dy[] = {-1,-2,-2,-1,1,2,2,1};
int n;
int cnt = 0;

void bfs(int x, int y, int cnt){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        for(int k=0; k<8; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                if(d[nx][ny] == 0 && c[nx][ny] != 0){
                    q.push(make_pair(nx,ny));
                    cnt += 1;
                }
            }
        }
    }
}

int main(){
    int t;
    int q,w,e,r;


    cin >> t;
    while(t--){
        cin >> n;

        memset(d,-1,sizeof(d));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                d[i][j] = 0;
            }
        }
        

    }


}