//
// Created by omri on 1/12/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_PATH_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_PATH_H

#include <vector>

template <class T>
class Path {

private:
    std::vector<T> path;

    double totalCost;

public:

    Path();

    Path(const std::vector<T> &path, double totalCost) : path(path), totalCost(totalCost) {}

    std::vector<T> getPath();

    double getCost();

};

#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_PATH_H
