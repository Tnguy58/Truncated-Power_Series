#ifndef SERIES_H_
#define SERIES_H_

#include <string>
#include <ostream>
#include <vector>

class Series {
    
public:
    Series(size_t);
    /* Creates Series object with all 0's for coefficients. */
    
    Series(size_t, double);
    /* Creates Series object with first coefficient assigned a specific value. */
    
    Series(size_t, std::vector<double>);
    /* Creates Series object with random coefficients. */
    
    void inverse();
    /* The inverse function. */
    
    std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& os, const Series& c);
    /* Displays the Series object. */
    
    void copy(Series& a);
    /* Copies the degree and the coefficients to the object. */
    
    Series operator=(Series& parameter);
    Series operator+(Series& parameter);
    Series operator-(Series& parameter);
    Series operator*(Series& parameter);
    Series operator/(Series& parameter);
    /* The various Series operations. */
    
    ~Series(void);
    /* Deconstructor. */
    
private:
    size_t degree;
    std::vector<double> coefficients;
};

#endif
