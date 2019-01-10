cmake_minimum_required(VERSION 3.13)
project(Advance_Programming_1_milestone2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Advance_Programming_1_milestone2 main.cpp Server.h MySerialServer.cpp MySerialServer.h ClientHandler.cpp ClientHandler.h CacheManager.h FileCacheManager.cpp FileCacheManager.h exceptions.h Searchable.h State.h Searcher.h Tests.cpp Tests.h BestFirstSearch.cpp BestFirstSearch.h Graph.cpp Graph.h)