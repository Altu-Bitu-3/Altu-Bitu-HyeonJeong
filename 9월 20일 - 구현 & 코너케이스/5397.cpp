#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string stackToString(stack<char>& left, stack<char>& right) {
    // 두 개의 스택을 하나의 문자열로 합치는 함수

    string password;
    // 왼쪽 스택의 top 부터 하나씩 오른쪽 스택에 삽입
    while (!left.empty()) { //왼쪽스택 비지 않은 경우
        right.push(left.top());
        left.pop();
    }
    // 현재 오른쪽 스택의 top에는 password의 앞글자부터 저장된 상태
    while (!right.empty()) {
        password += right.top(); //위에 있는것부터 저장
        right.pop(); // 위에거 제거
    }
    return password;
}

string findPassword(string log) { //비밀 번호 찾기
    stack<char> left;   //커서 이전 내용을 저장
    stack<char> right;  //커서 이후 내용을 저장

    for (int i = 0; i < log.length(); i++) { // 문자열 길이만큼 진행
        switch (log[i]) { //문자열인지 화살표, 백스페이스인지
            case '-':  //현재 커서 앞에 있는 글자 삭제
                if (!left.empty()) { // 왼쪽에 글자 없는 경우
                    left.pop(); //글자 지우기
                }
                break;
            case '<':  //커서를 왼쪽으로 이동
                if (!left.empty()) { //왼쪽에 글자 없는 경우
                    right.push(left.top()); //오른쪽에 위에있는거 넣기
                    left.pop(); //그리고 위에있는거 지우기
                }
                break;
            case '>':  //커서를 오른쪽으로 이동
                if (!right.empty()) { //오른쪽으로 이동할 수 있는 경우
                    left.push(right.top()); //오른쪽에있는거 왼족스택에 넣기
                    right.pop(); // 오른쪽 글자 지우기
                }
                break;
            default:  //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 left에 삽입
                left.push(log[i]); //커서보다 왼쪽이라 왼쪽에 삽입
        }
    }

    string password = stackToString(left, right); //스택에 있는거 string으로 변환
    return password; //password 반환
}


int main() {
    int tc;
    //입력
    cin >> tc; // 케이스 개수 입력

    // 출력
    while(tc--) {
        string s; // 문자열
        cin >> s; // 비밀번호 입력
        cout << findPassword(s) << '\n'; // 비밀번호 찾아내기
    }
    return 0;
}