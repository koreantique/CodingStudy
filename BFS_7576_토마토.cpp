#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int n,m;
int box[1001][1001];
int check[1001][1001];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};


int main(){
    cin >> m >> n;
    queue<pair<int,int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> box[i][j];
            check[i][j] = -1; //-1이 방문하지 않은 상태

            if(box[i][j] == 1){
                q.push(make_pair(i,j));
                check[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k=0; k<4; k++){
            int nx = x+dx[k];
            int ny = y+dy[k];

            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(box[nx][ny] == 0 && check[nx][ny] == -1){
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = check[x][y] + 1;
                }
            }
        }
    }

    int max_day = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(check[i][j] > max_day) {
                max_day = check[i][j];
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(box[i][j] == 0 && check[i][j] == -1) {
                max_day = -1;
            }
        }
    }


    cout << max_day << endl;

}