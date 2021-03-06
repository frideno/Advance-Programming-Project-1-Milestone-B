//
// created by omri & gal on 12/15/18.
//

#include <cmath>
#include "Utils.h"

// turn string to int.
double Utils::to_number(string s) {
    if (s == "")
        return  0;
    std::string::size_type sz;     // alias of size_t

    return std::stod(s, &sz);
}

bool Utils::getNArguments(int& N) {
    if (N == 0)
        return false;
    N--;
    return true;
}

template <class T>
vector<vector<T>> Utils::split(vector<T> str, T token) {

    vector<vector<T>> splited;

    int i = 0, j = 0;

    while (i < str.size()) {

        j = i;
        while (j < str.size() && str[j] != token) {
            j++;
        }

        // if found at j, cut the substring from i to j and push it to splited vector.
        typename vector<T>::const_iterator first = str.cbegin() + i;
        typename vector<T>::const_iterator last = str.cbegin() + j;
        vector<T> newVec(first, last);
        splited.push_back(newVec);
        i = j + 1;
    }
    return splited;
}

vector<string> Utils::strSplit(string str, char token) {
    vector<string> answer;
    vector<vector<char>> splittedInChars = split(vector<char>(str.begin(), str.end()), token);

    // turns each vector<char> to string.
    for (vector<char>& v: splittedInChars) {
        answer.push_back(string(v.begin(), v.end()));
    }

    return answer;
}

string Utils::to_string(double d) {
    // for double that are integer values:

    if ((double)((int) d) == d)
        return to_string((int) d);

    // if its infitity or -infitiy
    else if (d == INFINITY)
        return "-1";

    else if (d == -INFINITY)
        return "-inf";

    return to_string(d);
}

string Utils::to_string(int i) {
    return std::to_string(i);
}



