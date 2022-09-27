#include<iostream>
#include<string>
using namespace std;
/*
통화 시간이 최대 60까지이므로 입력받은 통화 시간만큼 분당 요금을 더해주는 반복문으로 풀이
->7시~18시 : +10원
->그 외: +5원
*/
int calculateCharge(int h, int m, int time) {
    int ans = 0; //요금
    //통화 시각이 0이 될 때까지 반복
    while (time--) {
        if (h >= 7 && h < 19) { //시간이 7~19까지 일경우
            ans += 10; // 1분에 10원
        }
        else {
            ans += 5; // 1분에 5원
        }
        h += (++m / 60) % 24; // 1분 더했을때 시간으로 넘어가는지
        m %= 60; //시간으로 넘어간경우 분 변경
    }
    return ans; // 값 반환
}

int main() {
    int n, m, time;
    int charge = 0; //요금
    string h; // 전화 건 시간

    cin >> n; // 전화건 횟수

    while(n--){
        getline(cin, h, ':'); //구분자 : 까지 시간 저장
        cin >> m >> time; //분과 통화 시간 저장
        charge += calculateCharge(stoi(h),m,time); // 요금 계산하기
    }

    cout << charge; //요금 출력
}