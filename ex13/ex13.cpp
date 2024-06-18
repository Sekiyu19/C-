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

double median(std::vector<double> hw){
  int size=hw.size();
  double mid;
  //データの入力がない場合
  if(size == 0){
    mid = 0.0;
    return mid;
  }
  std::sort(hw.begin(), hw.end());//ソート
  //中間値の計算
  mid = size/2;
  if(size%2 == 0)return (hw[mid] + hw[mid-1])/2;
  else return hw[mid];
}
 //最終成績の計算
double grade(const double& midterm, const double& final, const std::vector<double>& hw){
  double ex;
  ex = median(hw);
  return 0.2*midterm + 0.4*final + 0.4*ex;
}

std::istream& read_hw(std::istream& is, std::vector<double>& v){
  //double型以外が入力されても終了する
  if(is){
    double x;
    v.clear();
    while(is >> x){
      v.push_back(x);
    }
    is.clear();
  }
  return is;
}

/*
    Core class
        Provide core functions for student information
*/
class Core{
    //  Put code below
  friend class Student_info;
  
private:
  std::string n;
  
protected:
  double midterm, final;
  std::vector<double> homework;
  std::istream& read_common( std::istream& in) {
    in >> n >> midterm >> final;
    return in;
  }
  virtual Core* clone() const{return new Core(*this);};
  
public:
  Core( ) : midterm(0), final(0){};
  Core(std::istream& is){read(is);};
  std::string name( ) const {return n;};
  virtual std::istream& read( std::istream& in){
    read_common( in );
    ::read_hw( in, homework );
    return in;
  }
  virtual double grade( ) const{
    return ::grade(midterm, final, homework);
  }
};

/*
    Grad class
        Provide a class for a graduate student
*/
class Grad: public Core {
    //  Put code below
private:
  double thesis;

protected:
  virtual Core* clone() const{return new Grad(*this);};

public:
  Grad( ) : thesis(0){};
  Grad( std::istream& is){read(is);};
  std::istream& read( std::istream& in){
    read_common(in);
    in >> thesis;
    ::read_hw(in, homework);
    return in;
  }
  double grade( ) const{
    return std::min(Core::grade(), thesis);
  }
};

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
  Student_info( ) : cp( 0 ) { };
  Student_info( std::istream& is ) : cp( 0 ) { read(is); };
  Student_info( const Student_info& s ) : cp(0){if(s.cp)cp = s.cp->clone();};
  // ~Student_info( ) { delete cp; }
  std::istream& read( std::istream& is){
    delete cp;
    char ch;
    is >> ch;
    if(ch == 'u'){
      cp = new Core(is);
    }
    else{
      cp = new Grad(is);
    }
    return is;
  }
  std::string name( ) const {
    if(cp) return cp->name();
    else throw std::runtime_error("uninitialized");
  }
  bool valid(){
    if(cp->homework.size() == 0)return false;
    else return true;
  }
  double grade(){
    return cp->grade();
  } 
  static bool compare(const Student_info& s1, const Student_info& s2) {
    return s1.name() < s2.name();
  }
};

/*
    main()
*/
int main(int argc, char* argv[])
{
    std::vector<Student_info> students;
    Student_info record, temp;
    std::string::size_type maxlen = 0;
    int f = 1;

    while( record.read(std::cin) ){
        maxlen = std::max( maxlen, record.name().size() );
        students.push_back( record );
    }

    std::sort(students.begin(), students.end(), Student_info::compare);//何故か機能しない
    //バブルソートをする
  //   while(f){
  //    f = 0;
  //    for(int j = students.size()-1; j >= 1 ; j--){
  //     if(students[j].name() < students[j-1].name()){
  //      temp = students[j];
	//      students[j] = students[j-1];
	//      students[j-1] = temp;
  //      f = 1;
  //     }
  //   }
  // }

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
            std::cout << "Cannot evaluate";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
