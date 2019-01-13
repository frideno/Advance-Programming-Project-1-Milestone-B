//
// Created by omri on 1/12/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_PATH_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_PATH_H

#include <vector>

template <class T>
class Path {

private:
    std::vector<T> _path;

    double totalCost = -1;

public:

    Path() {}; // enpty path.

    Path(const std::vector<T> &path, double totalCost) : _path(path), totalCost(totalCost) {}

    inline std::vector<T> getPath() {return _path;}

    inline double getCost() {return totalCost;};

};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_PATH_H
