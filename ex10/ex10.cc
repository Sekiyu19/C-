#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Student_info {
    public:
        string student_id() const { return StudentId; };
        string first_name() const { return FirstName; };
        string last_name() const { return LastName; };
        double midterm_score() const { return MidtermScore; };
        double final_score() const { return FinalScore; };
        vector<double> exercise_scores() const { return exerciseScores; };
        void student_id(const string& StudentId) { this->StudentId = StudentId; };
        void first_name(const string& FirstName) { this->FirstName = FirstName; };
        void last_name(const string& LastName) { this->LastName = LastName; };
        void midterm_score(const double& MidtermScore) { this->MidtermScore = MidtermScore; };
        void final_score(const double& FinalScore) { this->FinalScore = FinalScore; };
        void exercise_scores(const vector<double>& exerciseScores) { this->exerciseScores = exerciseScores; };
        double median() {
            vector<double> eScores = exercise_scores();
            vector<double>::size_type size = eScores.size(), mid;
            if(size == 0) {
                return 0;
            }
            sort(eScores.begin(), eScores.end());
            mid = size / 2;
            if(size % 2 == 0) {
                return (eScores.at(mid) + eScores.at(mid - 1)) / 2;
            }
            return eScores.at(mid);
        }
        double grade() {
            return midterm_score()*0.2 + final_score()*0.4 + median()*0.4;
        };
        Student_info() { student_id(""); first_name(""); last_name(""); midterm_score(0); final_score(0); exercise_scores().clear(); }; 
        Student_info(const string& StudentId, string& FirstName, string& LastName, const double& MidtermScore, const double& FinalScore, const vector<double>& exerciseScores) { student_id(StudentId); first_name(FirstName); last_name(LastName); midterm_score(MidtermScore); final_score(FinalScore); exercise_scores(exerciseScores); };
        bool operator<(const Student_info &another) const {
            return FirstName != another.FirstName ? FirstName < another.FirstName : LastName < another.LastName;
        };
    private:
        string StudentId, FirstName, LastName;
        double MidtermScore, FinalScore;
        vector<double> exerciseScores;
};

bool isNumber(const string& str) {
  for (char const& c : str) {
    if (std::isdigit(c) == 0) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1; 
    }

    string inputFile = argv[1];
    string outputFile = argv[2];

    ifstream input(inputFile);
    if (!input.is_open()) {
        return 1; 
    }
    int count = 0;
    string student_id;
    string first_name;
    string last_name;
    double midterm_score;
    double final_score;
    vector<double> exercise_scores;
    double exercise_score;
    vector<Student_info> student_infos;
    Student_info student_info;
    string str, score;

    student_infos.clear();
    while(input >> student_id >> first_name >> last_name >> midterm_score >> final_score) {
        exercise_scores.clear();
        getline(input, str);
        stringstream ss{str};
        while(getline(ss, score, ' ')) {
            try{
                exercise_score = stod(score);
                exercise_scores.push_back(exercise_score);
            }
            catch(const std::invalid_argument& e){
            }
        }
        student_info.student_id(student_id);
        student_info.first_name(first_name);
        student_info.last_name(last_name);
        student_info.midterm_score(midterm_score);
        student_info.final_score(final_score);
        student_info.exercise_scores(exercise_scores);
        student_infos.push_back(student_info);
    }
    input.close();

    sort(student_infos.begin(), student_infos.end());

    ofstream output(outputFile);
    if (!output.is_open()) {
        return 1;
    }
    output << "+==============+==============+===========+=======+=======+====+" << endl;
    for(int i = 0; i < student_infos.size(); i++) {
        if (student_infos.at(i).exercise_scores().size()) {
            output << fixed << setprecision(1) << "| " << left << setw(12) << student_infos.at(i).last_name() << " | " << setw(12) << student_infos.at(i).first_name() << " | " << setw(9) << student_infos.at(i).student_id() << " | " << right << setw(5) << student_infos.at(i).median() << " | " << setw(5) << student_infos.at(i).grade() << " | ";
            if (student_infos.at(i).grade() >= 90) {
                output<< "A  |" << endl;
            } else if (student_infos.at(i).grade() >= 80) {
                output<< "B+ |" << endl;
            } else if (student_infos.at(i).grade() >= 70) {
                output<< "B  |" << endl;
            } else if (student_infos.at(i).grade() >= 60) {
                output<< "C+ |" << endl;
            } else if (student_infos.at(i).grade() >= 50) {
                output<< "C  |" << endl;
            } else {
                output<< "D  |" << endl;
            }
        } else {
            output << fixed << setprecision(1) << "| " << left << setw(12) << student_infos.at(i).last_name() << " | " << setw(12) << student_infos.at(i).first_name() << " | " << setw(9) << student_infos.at(i).student_id() << " | No grade           |" << endl;
        }
        count++;
        if(count % 5 == 0) {
            output << "+--------------+--------------+-----------+-------+-------+----+" << count << endl;
        }
    }
    output << "+==============+==============+===========+=======+=======+====+" << endl;
    output.close();

    return 0;
}
