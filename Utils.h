//
// created by omri & gal on 12/15/18.
//

#ifndef PROG1PROJECT_UTILS_H
#define PROG1PROJECT_UTILS_H

#include <string>
#include <vector>

using namespace std;

class Utils {
public:

    // cast string to int.
    static double to_number(string s);

    // returns true N times, than after that false.
    static bool getNArguments(int& N);

    // splits a string str by a token. returned in vector. if the token not found, str returned as
    // the only in the vector.
    template <class T>
    static vector<vector<T>> split(vector<T>, T token);


    // split string using split.
    static vector<string> strSplit(string str, char token);


    };


#endif //PROG1PROJECT_UTILS_H
