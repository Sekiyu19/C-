/*
 * @file SkeltonEx13.cpp
 * @brief Skelton of Ex-13 ofin PL04: Programming C++
 * @author Keitaro Naruse
 * @date 2022-11-17
 * @copyright MIT License
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
using namespace std;

/*
    Core class
        Provide core functions for student information
*/
class Core{
    //  Put code below
    public:
        Core( );
        Core( std::istream& );
        std::string name( ) const;
        virtual double grade( ) const;
        virtual std::istream& read( std::istream& );
        std::istream& read_hw(std::istream& is, std:: vector<double>& v);
        double median() const;
        vector<double> getHomework() const { return homework; };
    protected:
        std::istream& read_common( std::istream& );
        double midterm, final;
        std::vector<double> homework;
    private:
        std::string n;
};

Core::Core( ) : midterm(0), final(0) { }

Core::Core( std::istream& is ) { read(is); }

std::string Core::name( ) const { return n; }

double Core::median() const {
    vector<double> homeworks = homework;
    vector<double>::size_type size = homeworks.size(), mid;
    if(size == 0) {
        return 0;
    }
    sort(homeworks.begin(), homeworks.end());
    mid = size / 2;
    if(size % 2 == 0) {
        return (homeworks.at(mid) + homeworks.at(mid - 1)) / 2;
    }
    return homeworks.at(mid);
}

double Core::grade( ) const {
    return midterm*0.2 + final*0.4 + median()*0.4;
}

std::istream& Core::read_common( std::istream& in ) {
    in >> n >> midterm >> final;
    return in;
}

std::istream& Core::read_hw(std::istream& is, std::vector<double>& v) {
    if( is ) {
        double x;
        v.clear();
        while( is >> x ){
            v.push_back( x );
        }
        is.clear();
    }
    return is;
}

std::istream& Core::read( std::istream& in ) {
    read_common( in );
    read_hw( in, homework );
    return in;
}

/*
    Grad class
        Provide a class for a graduate student
*/
class Grad : public Core {
    //  Put code below
    public:
        Grad( );
        Grad( std::istream& );
        double grade( ) const;
        std::istream& read( std::istream& );
    private:
        double thesis;
};

Grad::Grad ( ) : thesis (0) { }

Grad::Grad( std::istream& is ) { read(is); }

double Grad::grade() const {
    return min( Core::grade(), thesis );
}

std::istream& Grad::read( std::istream& in ) {
    read_common( in );
    in >> thesis;
    read_hw( in, homework );
    return in;
}

/*
    Student_info class
        Provide a hundle class
*/
class Student_info{
//  Put code below
//  Student_info class should have valid() function
    private:
        Core *cp;
    public:
        Student_info( ) : cp( 0 ) { }
        Student_info( std::istream& is ) : cp( 0 ) { read(is); }
        std::istream& read( std::istream& in ) ;
        std::string name( ) const {
            if(cp) return cp->name();
            else throw std::runtime_error("uninitialized");
        }
        double grade( ) const {
            if(cp) return cp->grade();
            else throw std::runtime_error("uninitialized");
        }
        static bool compare(const Student_info& s1, const Student_info& s2) {
            return s1.name() < s2.name();
        }
        bool valid() {
            if(cp) return cp->getHomework().size() != 0;
            else throw std::runtime_error("uninitialized");
        }
};

std::istream& Student_info::read( std::istream& is) {
    delete cp;
    char ch;
    is >> ch;
    if(ch == 'u') {
        cp = new Core( is );
    } else{
        cp = new Grad( is );
    }
    return is;
}

/*
    main()
*/
int main(int argc, char* argv[])
{
    std::vector<Student_info> students;
    std::string::size_type maxlen = 0;

    while(true){
        Student_info record;
        record.read(cin);
        if (record.name().size() == 0) {
            break;
        }
        maxlen = std::max( maxlen, record.name().size() );
        students.push_back( record );
    }
    
    std::sort(students.begin(), students.end(), Student_info::compare);
    
    for(std::vector<Student_info>::size_type i = 0; i != students.size(); ++i){
        std::cout << students[i].name()
	      << std::string(maxlen + 1 - students[i].name().size(), ' ');
        if( students[i].valid() ){
            double final_grade = students[i].grade();
            std::streamsize prec = std::cout.precision();
            std::cout << std::setprecision(3) << final_grade
		    << std::setprecision(prec);
        }
        else{
            std::cout << "Caanot evaluate";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
