//
// Created by omri on 1/8/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_TESTSEARCHER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_TESTSEARCHER_H


#include <thread_db.h>
#include "Searcher.h"
#include "Searchable.h"

#include "CubeSearch.h"

class Tests {

public:

    template <class T>
    static void MySearcher(Searcher<T>& searcher, Searchable<T>& searchable);

};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_TESTSEARCHER_H
