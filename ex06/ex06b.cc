#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<string> str;
    string c, s, t;
    vector<string>::iterator it;

    str.clear();
    while(cin >> c) {
        if(c == "a") {
            cin >> s;
            str.push_back(s);
        }
        if(c == "d") {
            cin >> s;
            for(it = str.begin(); it != str.end(); it++) {
                if(*it == s) {
                    str.erase(it--);
                }
            }
        }
        if(c == "i") {
            cin >> s >> t;
            for(it = str.begin(); it != str.end(); it++) {
                if(*it == s) {
                    it = str.insert(it, t);
                    it++;
                }
            }
        }
        if(c == "r") {
            cin >> s >> t;
            for(it = str.begin(); it != str.end(); it++) {
                if(*it == s) {
                    *it = t;
                }
            }
        }
        if(c == "p") {
            for(it = str.begin(); it != str.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    
    return 0;
}