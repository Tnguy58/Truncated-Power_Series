#include <iomanip>
#include <iostream>
#include <sstream>
#include <ctime>
#include "series.h"

using namespace std;

Series::Series(size_t degree_num) {
    degree = degree_num;
    
    for (int i = 0; i < degree_num + 1; i++) {
        coefficients.push_back(0);
    }
}

Series::Series(size_t degree_num, double leading_coefficient) {
    degree = degree_num;
    
    coefficients.push_back(degree);
    
    for (int i = 1; i < degree_num + 1; i++) {
        coefficients.push_back(0);
    }
}

Series::Series(size_t degree_num, vector<double> tim) {
    degree = degree_num;
    
    for (int i = 0; i < degree_num + 1; i++) {
        double num = tim.at(i);
        coefficients.push_back(num);
    }
}

Series::~Series(void) {
    (*this).degree = -1;
}

string Series::to_string() const {
    using std::ostringstream;
    ostringstream s;
    
    for(int i = 0; i < degree + 1; ++i) {

        if (i < 1) {
            s << scientific << setprecision(4) << coefficients.at(i);
        }
        // If coefficients.at(i) is positive add + sign, else don't add +.
        else if (coefficients.at(i) >= 0) {
            s << scientific << setprecision(4) << "+" << coefficients.at(i) << "*t^" << i;
        }
        else {
            s << scientific << setprecision(4) << coefficients.at(i) << "*t^" << i;
        }
    }
    s << "+0" << "(t^" << coefficients.size() << ")" << endl; // 0(t^(degree+1)).
    
    return s.str();
}

ostream& operator<<(ostream& os, const Series& c) {
    os << c.to_string();
    return os;
}

void Series::copy(Series& a) {
    (*this).degree = a.degree;
    (*this).coefficients.erase((*this).coefficients.begin(),(*this).coefficients.end());
    
    // Copying over coefficients into current object's coefficients vector.
    for (int i = 0; i < (*this).degree + 1; i++) {
        double d = a.coefficients.at(i);
        (*this).coefficients.push_back(d);
    }
}

Series Series::operator=(Series& parameter) {
    (*this).copy(parameter);
    return *this;
}

Series Series::operator+(Series& parameter) {
    // Creates a temp vector then empty it.
    Series temp((*this).degree);
    temp.coefficients.erase(temp.coefficients.begin(), temp.coefficients.end());
    
    // Componentwise addition of two vectors.
    for (int i = 0; i < temp.degree + 1; i++) {
        double num = (*this).coefficients.at(i) + parameter.coefficients.at(i);
        temp.coefficients.push_back(num);
    }
    return temp;
}

Series Series::operator-(Series& parameter) {
    Series temp((*this).degree);
    temp.coefficients.erase(temp.coefficients.begin(), temp.coefficients.end());
    
    for (int i = 0; i < temp.degree + 1; i++) {
        double num = (*this).coefficients.at(i) - parameter.coefficients.at(i);
        temp.coefficients.push_back(num);
    }
    return temp;
}

Series Series::operator*(Series& parameter) {
    Series temp((*this).degree);
    temp.coefficients.erase(temp.coefficients.begin(), temp.coefficients.end());
    
    for (int i = 0; i < temp.degree + 1; i++) {
        double num = (*this).coefficients.at(i) * parameter.coefficients.at(i);
        temp.coefficients.push_back(num);
    }
    return temp;
}

void Series::inverse() {
    for (int i = 0; i < (*this).degree + 1; i++) {
        double num = 1.0/(*this).coefficients.at(i);
        (*this).coefficients.at(i) = num;
    }
}

Series Series::operator/(Series& parameter) {
    Series temp((*this).degree);
    temp.coefficients.erase(temp.coefficients.begin(), temp.coefficients.end());
    
    temp = (*this);
    temp.inverse();
    
    for (int i = 0; i < temp.degree + 1; i++) {
        double num = temp.coefficients.at(i) * parameter.coefficients.at(i);
        temp.coefficients.at(i) = num;
    }
    return temp;
}
