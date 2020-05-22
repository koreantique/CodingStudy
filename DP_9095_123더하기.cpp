#include <iostream>

using namespace std;

long long d[1000001] = {0,};
const long long mod = 1000000009LL;
int go(int n);

int main(){
    int t;
    int n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        cout << go(n) << endl;
    }
    
}

int go(int n){

    if(n == 0) return 1;
    if(n == 1) return 1;
    if(n == 2) return 2;
    
    if(d[n] > 0) return d[n] % mod;
    d[n] = go(n-1) + go(n-2) + go(n-3);
    return d[n] % mod;
}

//재귀 X

#include <iostream>

using namespace std;

int N; 
int store[11]; 
// 점화식 f(x)=f(x-1)+f(x-2)+f(x-3)
int f(void)
{
        store[1] = 1; //1
        store[2] = 2; //1+1, 2
        store[3] = 4; //1+1+1, 1+2, 2+1, 3

        for (int i = 4; i <= N; i++)
               store[i] = store[i - 1] + store[i - 2] + store[i - 3];
        return store[N];
}

int main(void)
{
        int T;
        cin >> T;
        for (int i = 0; i < T; i++)
        {
               cin >> N;
               cout << f() << endl;
        }
        return 0;
}