//길찾기 bfs는 단방향 진행이지만
//지금 푸는 문제는 다발성 문제이다.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool flag = false;
int day = 0;
int M, N;
int nx, ny;
int box[1001][1001];
int check[1001][1001];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    check[x][y] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            nx = x+dx[k];
            ny = y+dy[k];
            if(0<= nx && nx < M && 0 <= ny && ny < N){
                if(box[nx][ny] == 0 && check[nx][ny] == 0){
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = 1;
                    flag = true;
                }
            }
        }
        if(flag == true) day++;
        flag = false;
    }
}

int main(){
    cin >> M >> N;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> box[i][j];
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(box[i][j] == 1){
                bfs(i,j);
            }
        }
    }
    cout << day << endl;
}

