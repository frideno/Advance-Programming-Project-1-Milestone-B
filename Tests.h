//
// Created by omri on 1/8/19.
//

#ifndef ADVANCE_PROGRAMMING_1_MILESTONE2_TESTSEARCHER_H
#define ADVANCE_PROGRAMMING_1_MILESTONE2_TESTSEARCHER_H


#include <thread_db.h>
#include "Searcher.h"
#include "Searchable.h"
#include "Graph.h"

class Tests {

    template <class T>
    void testSearcher(Searcher<T>& searcher, Searchable<T>& searchable);

    template <class T>
            Graph<string>* buildGraphFromString(vector<string>);


};


#endif //ADVANCE_PROGRAMMING_1_MILESTONE2_TESTSEARCHER_H
