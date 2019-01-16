cmake_minimum_required(VERSION 3.13)
project(Advance_Programming_1_milestone2)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS -pthread)

add_executable(Advance_Programming_1_milestone2 main.cpp Server.h MySerialServer.cpp Utils.h Utils.cpp MySerialServer.h ClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h exceptions.h Searchable.h State.h Searcher.h Tests.cpp Tests.h MyClientHandler.cpp MyClientHandler.h CubeSearch.cpp CubeSearch.h CompareAlgorithms.cpp CompareAlgorithms.h Path.h  TestSearcher.h Compare.h CompareStates.h TestSearcher.h Solver.h SearcherSolver.h MyParallelServer.cpp MyParallelServer.h NormalState.h  A_Star.h AbstractSearcher.h BestFirstSearch.h  BFS.h SimpleCompare.h DFS.h HeuristicCompare.h State.h NormalState.h StateCompare.h SearcherState.h Heuristic.h HeuristicManhatan.h)