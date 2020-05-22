#include <iostream>
#include <queue>

using namespace std;

char map[11][11];
int visit[11][11][11][11] = {0, };
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int RESULT = -1; //정답은 -1로 선언

//공의 정보를 담는 구조체, count는 움직인 횟수
struct INFO{
    int rx, ry, bx, by, count;
};

//시작점을 담을 객체
INFO start;

void bfs(){
    queue<INFO> q;
    q.push(start);
    visit[start.rx][start.ry][start.bx][start.by] = 1;

    while(!q.empty()){
        INFO cur = q.front(); q.pop();
        if(cur.count > 10) break;
        if(map[cur.rx][cur.ry] == 'O' && map[cur.bx][cur.by] != 'O'){
            RESULT = cur.count;
            break;
        }
        for(int k=0; k<4; k++){
            int next_rx = cur.rx;
            int next_ry = cur.ry;
            int next_bx = cur.bx;
            int next_by = cur.by;

            while(1){
                if(map[next_rx][next_ry] != '#' && map[next_rx][next_ry] != 'O'){
                    next_rx += dx[k];
                    next_ry += dy[k];
                }
                else{
                    if(map[next_rx][next_ry] == '#'){
                        next_rx -= dx[k];
                        next_ry -= dy[k];
                    }
                    break; //
                }
            }
            while(1){
                if(map[next_bx][next_by] != '#' && map[next_bx][next_by] != 'O'){
                    next_bx += dx[k];
                    next_by += dy[k];
                }
                else{
                    if(map[next_bx][next_by] == '#'){
                        next_bx -= dx[k];
                        next_by -= dy[k];
                    }
                    break; //
                }
            }

            if(next_rx == next_bx && next_ry == next_by){
                int red_dist = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
                int blue_dist = abs(next_bx - cur.bx) + abs(next_by - cur.by);

                if(red_dist > blue_dist){
                    next_rx -= dx[k];
                    next_ry -= dy[k];
                }

                if(red_dist < blue_dist){
                    next_bx -= dx[k];
                    next_by -= dy[k];
                }
            }

            if(visit[next_rx][next_ry][next_bx][next_by] == 0){
                visit[next_rx][next_ry][next_bx][next_by] = 1;
                INFO next;
                next.rx = next_rx;
                next.ry = next_ry;
                next.bx = next_bx;
                next.by = next_by;
                next.count = cur.count+1;
                q.push(next);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        scanf("%s", map[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 'R'){
                start.rx = i; start.ry = j;
            }
            if(map[i][j] == 'B'){
                start.bx = i; start.by = j;
            }
        }
    }

    bfs();
    cout << RESULT << endl;
}
