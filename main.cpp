// MCS 360 Project Two by Timothy Nguyen

#include "series.h"
#include <iostream>

using namespace std;

/*
 Creates random vector for third constructor.
 */
void random_number(size_t degree, vector<double>&);

int main() {
    
    size_t degree_x = 3;
    Series X(degree_x);
    
    cout << "Constructor 1 test: " << X;
    
    size_t degree_y = 3;
    double first_degree = 2.0;
    Series Y(degree_y, first_degree);
    
    cout << "Constructor 2 test: " << Y;
    
    size_t degree_z = 3;
    vector<double> tom;
    random_number(degree_z, tom);
    Series Z (degree_z, tom);
    
    cout << "Constructor 3 test " << Z;
    
    size_t degree;
    
    cout << "Testing the arithmetic on truncated power series ... " << endl;
    cout << "Give the degree : ";
    
    cin >> degree;
    
    vector<double> tim;
    random_number(degree, tim);
    Series A(degree, tim);

    cout << "A random series of degree " << degree << ", called A," << endl;
    cout << " series A : " << A;
    
    vector<double> jan;
    random_number(degree, jan);
    Series B(degree, jan);
    
    cout << "and another random series of degree " << degree << ", called B." << endl << " series B : " << B;
  
    cout << "    A + B : " << A + B;
    
    cout << "A + B - B: " << A + B - B;
    
    cout << "    A * B: " << A * B;
    
    cout << "A * B / B: " << B / B * A;
    
    cout << endl << "Testing Newton's method on the square root of a random series : " << endl;
    
    Series C(4);
    
    cout << "         x = " << C;
    
    for (int i = 0; i < 5; i++) {
        cout << "at step " << i << " :" << endl;
        cout << "fx = " << endl;
        cout << "dx = " << endl;
        cout << " x = " << endl;
    }
    
    cout << "   sqrt(x) = " << endl;
    cout << "sqrt(x)**2 = " << endl;
    
    return 0;
}

void random_number(size_t degree, vector<double>& tim) {
    // Chooses number between -1 and 1 and stores in the vector coefficients.
    for (int i = 0; i < degree + 1; i++) {
        
        // Using nanoseconds to seed the random number generator.
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        srand((time_t)ts.tv_nsec);
        
        double num = (rand() % 90000 + 10000)/100000.0; // Picks a random 5 digit decimal.
        
        int randNum = (rand() % 2) + 1; // Picks a random number, 1 or 2.
        
        // If randNum == 1, num stays positive else num becomes negative.
        if (randNum != 1) {
            num = -num;
        }

        tim.push_back(num);
    }
}
