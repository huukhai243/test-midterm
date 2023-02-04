#include<iostream>
using namespace std;

void XuLY(int x, int* a, bool* check, int n, int &max, int GiaTri){
    if(x == n-1){
        if(max < GiaTri)
            max = GiaTri;
    }
    for(int i=x; i<n; i++){
        if(check[i] == false){
            if(x > 1 && check[x-1] == true && check[x-2] == true){
                XuLY(x+1, a, check, n, max, GiaTri);
                break;
            }else{
                check[i] = true;
                XuLY(x+1, a, check, n, max, GiaTri + a[i]);
                check[i] = false;
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    if(n < 1 || n > 100000) return 0;

    int* a = new int[n];
    bool* check = new bool[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        check[i] = false;
    }
    int max = -1;
    XuLY(0, a, check, n, max, 0);
    cout << max;

    return 0;
}