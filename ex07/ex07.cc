#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int main() {
    int N, M;
    string str1, str2;
    vector<string> s;
    bool flg;
    s.clear();
    
    cin >> N;
    for(int i = 0; i <= N; i++) {
        getline(cin, str1);
        s.push_back(str1);
    }
    
    cin >> M;
    for(int i = 0; i < M; i++) {
        flg = true;
        cin >> str1;
        for(int j = 0; j < N; j++) {
            stringstream ss(s.at(j));
            while(getline(ss, str2, ' ')) {
                if(str1 == str2) {
                    flg = false;
                    cout << j << endl;
                }
            }
        }
        if(flg) {
            cout << "-1" << endl;
        }
    }
}