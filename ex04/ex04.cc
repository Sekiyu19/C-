#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double sum(vector<double>& v) {
    vector<double>::size_type size = v.size();
    if(size == 0) {
        return 0;
    }
    double sum = 0;
    for(int i = 0; i < v.size(); i++) {
        sum += v.at(i);
    }
    return sum;
}

double average(vector<double>& v) {
    vector<double>::size_type size = v.size();
    if(size == 0) {
        return 0;
    }
    double sum = 0;
    for(int i = 0; i < v.size(); i++) {
        sum += v.at(i);
    }
    return sum / size;
}

double median(vector<double>& v) {
    vector<double>::size_type size = v.size(), mid;
    if(size == 0) {
        return 0;
    }
    sort(v.begin(), v.end());
    mid = size / 2;
    if(size % 2 == 0) {
        return (v.at(mid) + v.at(mid - 1)) / 2;
    }
    return v.at(mid);
}

int main() {
    int count = 0;
    string student_id;
    string first_name;
    string last_name;
    double midterm_score;
    double final_score;
    vector<double> exercise_scores;
    double exercise_score;
    double s, a, m, t;

    cout << "+================+================+=========+========+========+========+========+" << endl;
    while(cin >> student_id >> first_name >> last_name >> midterm_score >> final_score) {
        exercise_scores.clear();
        while(cin >> exercise_score) {
            if(exercise_score == -1) {
                break;
            } else { 
                exercise_scores.push_back(exercise_score);
            }
        }
        s = sum(exercise_scores);
        a = average(exercise_scores);
        m = median(exercise_scores);
        t = midterm_score*0.2 + final_score*0.4 + m*0.4;
        count++;
        cout << "| " << first_name;
        for(int i = 0; i < 15 - first_name.size(); i++) {
            cout << " ";
        }
        cout << "| " << last_name;
        for(int i = 0; i < 15 - last_name.size(); i++) {
            cout << " ";
        }
        cout << "| " << student_id;
        for(int i = 0; i < 7 - student_id.size(); i++) {
            cout << " ";
        }
        cout << " | ";
        for(int i = 0; i < 11 - to_string(s).size(); i++) {
            cout << " ";
        }
        cout << fixed << setprecision(1) << s << " | ";
        for(int i = 0; i < 11 - to_string(a).size(); i++) {
            cout << " ";
        }
        cout  << a << " | ";
        for(int i = 0; i < 11 - to_string(m).size(); i++) {
            cout << " ";
        }
        cout << m << " | ";
        for(int i = 0; i < 11 - to_string(t).size(); i++) {
            cout << " ";
        }
        cout << t << " |" << endl;
        if(count % 5 == 0) {
            cout << "+----------------+----------------+---------+--------+--------+--------+--------+" << count << endl;
        }
    }
    cout << "+================+================+=========+========+========+========+========+" << endl;

    return 0;
}
