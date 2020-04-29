#include <iostream>
#include <queue>

using namespace std;


int n, k;
int d[100001];
int check[100001] = {0,};

void bfs(int x);

int main(){
    cin >> n >> k;
    bfs(n);
    cout << check[k]-1 <<endl;
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    check[x] = 1;

    while(!q.empty()){
        x = q.front();
        q.pop();

        //x+1, x-1, x*2에 대해서

        int nx = x+1;
        if( 0 <= nx && nx <= 100000){
            if(check[nx] == 0){
                q.push(nx);
                check[nx] = check[x] + 1;
            }
        }

        nx = x-1;
        if( 0 <= nx && nx <= 100000){
            if(check[nx] == 0){
                q.push(nx);
                check[nx] = check[x] + 1;
            }
        }

        nx = x*2;
        if( 0 <= nx && nx <= 100000){
            if(check[nx] == 0){
                q.push(nx);
                check[nx] = check[x] + 1;
            }
        }
    }
}