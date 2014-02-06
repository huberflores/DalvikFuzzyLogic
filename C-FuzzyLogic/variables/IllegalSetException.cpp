#include <iostream>
#include <exception>
using namespace std;

namespace variables {
    class IllegalSetException: public exception {
        public:
            const char* what() const throw () {
                return "The set is already registered";
            }
    } IllegalSet;
}

