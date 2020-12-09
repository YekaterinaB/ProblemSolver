cmake_minimum_required(VERSION 3.15)
project(ProblemSolver)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProblemSolver main.cpp Solver/MatrixSolver.h Solver/Solver.h Searcher/Searcher.h Maze/State.h Maze/MatrixMaze.h StringUtils.h Searcher/Astar.h Searcher/Astar.cpp Searcher/CustomPriorityQueue.h Solver/MathSolver.h Searcher/ReversePolishInterpreter.h Expression/Expression.h Searcher/ReversePolishInterpreter.cpp Expression/Expression.cpp)