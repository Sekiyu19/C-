#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, x, t, l, r, sum;
    std::vector<int> vec_x, vec_l, vec_r;

    cin >> n;
    vec_x.clear();
    for(int i = 0; i < n; i++) {
      cin >> x;
      vec_x.push_back(x);
    }
    cin >> t;
    vec_l.clear();
    vec_r.clear();
    for(int i = 0; i < t; i++) {
      cin >> l >> r;
      vec_l.push_back(l);
      vec_r.push_back(r);
    }

    for(int i = 0; i < t; i++) {
        sum = 0;
	  for(int j = vec_l.at(i); j < vec_r.at(i); j++) {
     	  sum += vec_x.at(j);
  	}
        cout << sum << endl;
    }
    
    return 0;
}
