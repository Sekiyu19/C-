#include <iostream>
#include <string>
using namespace std;

int main() {
    int count = 0;
    string student_id;
    string first_name;
    string last_name;    

    cout << "+================+================+===========+" << endl;
    while(cin >> student_id >> first_name >> last_name) {
      count++;
      cout << "|  " << last_name;
      for(int i = 0; i < 14 - last_name.size(); i++) {
	cout << " ";
      }
      cout << "|  " << first_name;
      for(int i = 0; i < 14 - first_name.size(); i++) {
	cout << " ";
      }
      cout << "|  " << student_id << "  |" << endl;
      if(count % 5 == 0) {
	cout << "+----------------+----------------+-----------+" << count << endl;
      }
    }
    cout << "+================+================+===========+" << endl;

    return 0;
}
