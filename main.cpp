#include <iostream>
#include "CacheManager.h"
#include "FileCacheManager.h"

int main() {

    // file cache manager test:

    FileCacheManager c;
    string s;
    for (int i =0; i< 5; i++) {
        cin >> s;
        if (c.isSolutionExists(s)) {
            cout << "exsists! " << c.getSolution(s) << endl;

        }
        else {
            cout << "new" << endl;
            c.saveSolution(s, "sol");
        }

    }
}