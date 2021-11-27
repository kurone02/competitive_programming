#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
const double SEC_PER_SEC = 6;
const double MIN_PER_SEC = (double)1 / 10;
const double MIN_PER_MIN = 6;
const double HOUR_PER_SEC = (double)1 / 120;
const double HOUR_PER_MIN = (double)1 / 2;
const double HOUR_PER_HOUR = 30;

double get_actual_angle(const double &x){
    if(x > 180) return 360 - x;
    else return x;
}

double Abs(double x){
    if(x < 0) x = -x;
    return get_actual_angle(x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("test.inp", "r")){
        freopen("test.inp", "r", stdin);
        //freopen("test.out", "w", stdout);
    }

    int nTest; cin >> nTest;
    while(nTest--){
        int h, m, s; cin >> h >> m >> s;
        double hour = HOUR_PER_HOUR * h + HOUR_PER_MIN * m + HOUR_PER_SEC * s;
        double minute = MIN_PER_MIN * m + MIN_PER_SEC * s;
        double second = SEC_PER_SEC * s;
        cout << fixed << setprecision(6) << min(Abs(second - minute), min(Abs(minute - hour), Abs(hour - second))) << '\n';
    }
    
    return 0;
}