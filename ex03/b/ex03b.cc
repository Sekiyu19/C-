#include <vector>
#include <iostream>
using namespace std;

int main() {
    int t, i, x;
    char c;
    std::vector<int> v;

    cin >> t;
    v.clear();
    for(int j = 0; j < t; j++) {
        cin >> c >> i;
        if(c == 'a') {
            cin >> x;
            v.insert(v.begin()+i, x);
        }
        if(c == 'd') {
            v.erase(v.begin()+i);
        }
        if(c == 'p') {
            cout << v.at(i) << endl;
        }
    }
    
    return 0;
}
