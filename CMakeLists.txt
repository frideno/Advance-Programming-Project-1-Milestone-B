cmake_minimum_required(VERSION 3.13)
project(Advance_Programming_1_milestone2)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS -pthread)

add_executable(Advance_Programming_1_milestone2 main.cpp Server.h MySerialServer.cpp Utils.h Utils.cpp MySerialServer.h ClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h exceptions.h Searchable.h State.h Searcher.h Tests.cpp Tests.h MyClientHandler.cpp MyClientHandler.h CubeSearch.cpp CubeSearch.h CompareAlgorithms.cpp CompareAlgorithms.h Path.h A_Star.h A_Star.cpp AbstractSearcher.cpp AbstractSearcher.h BestFirstSearch.h BestFirstSearch.cpp TestSearcher.h Compare.h DFS.h Heuristic.h HeuristicCompare.h HeuristicManhatan.h CompareStates.h TestSearcher.h Solver.h SearcherSolver.h MyParallelServer.cpp MyParallelServer.h)