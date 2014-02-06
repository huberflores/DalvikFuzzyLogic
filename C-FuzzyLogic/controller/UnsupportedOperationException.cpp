#include <iostream>
#include <exception>
using namespace std;

namespace controller {
    class UnsupportedOperationException: public exception {
        public :
            const char* what() const throw () {
                return "UnsupportedOperationException";
            }
    } UnsupportedOperation;
}

