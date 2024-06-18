#include <list>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

struct Word_count {
    string word;
    int count;
};

bool compare(const Word_count& x, const Word_count& y) {
    return x.word < y.word;
}

int main() {
    list<Word_count> word_count;
    Word_count wc;
    word_count.clear();
    list<Word_count>::iterator it;
    string chars1 = ".";
    string chars2 = ",";
    string chars3 = "(";
    string chars4 = ")";
    string chars5 = "\"";
    string chars6 = "\'";
    while(cin >> wc.word) {
        wc.word.erase(remove_if(wc.word.begin(), wc.word.end(),
                        [&chars1](const char &c) {
                            return chars1.find(c) != string::npos;
                        }),
                        wc.word.end());
        wc.word.erase(remove_if(wc.word.begin(), wc.word.end(),
                        [&chars2](const char &c) {
                            return chars2.find(c) != string::npos;
                        }),
                        wc.word.end());
        wc.word.erase(remove_if(wc.word.begin(), wc.word.end(),
                        [&chars3](const char &c) {
                            return chars3.find(c) != string::npos;
                        }),
                        wc.word.end());
        wc.word.erase(remove_if(wc.word.begin(), wc.word.end(),
                        [&chars4](const char &c) {
                            return chars4.find(c) != string::npos;
                        }),
                        wc.word.end());
        wc.word.erase(remove_if(wc.word.begin(), wc.word.end(),
                        [&chars5](const char &c) {
                            return chars5.find(c) != string::npos;
                        }),
                        wc.word.end());
        wc.word.erase(remove_if(wc.word.begin(), wc.word.end(),
                        [&chars6](const char &c) {
                            return chars6.find(c) != string::npos;
                        }),
                        wc.word.end());
        transform(wc.word.begin(), wc.word.end(), wc.word.begin(), ::tolower);
        if(word_count.size() == 0) {
            wc.count = 1;
            word_count.push_back(wc);
        } else {
            for(it = word_count.begin(); it != word_count.end(); it++) {
                if((*it).word == wc.word) {
                    (*it).count++;
                    break;
                }
            }
            if((*it).word != wc.word) {
                wc.count = 1;
                word_count.push_back(wc);
            }
        }
    }
    word_count.sort(compare);

    it = word_count.begin();
    while( it != word_count.end() ) {
        cout << it->word << " " << it->count <<endl;
        ++ it;
    }
    cout << endl;

    return 0;
}