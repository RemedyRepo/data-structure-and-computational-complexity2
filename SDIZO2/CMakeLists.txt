cmake_minimum_required(VERSION 3.24)
project(SDIZO2)

set(CMAKE_CXX_STANDARD 17)

add_executable(SDIZO2 main.cpp Graph_tools/Graph.cpp Graph_tools/Graph.h Graph_tools/Matrix.cpp Graph_tools/Matrix.h Graph_tools/List.cpp Graph_tools/List.h File_handling/Reader.cpp File_handling/Reader.h Prim/prim_implementation.cpp Prim/prim_implementation.h "Graph_tools/Structures/Kopiec Binarny/KopiecBinarny.cpp" "Graph_tools/Structures/Tablica Dynamiczna/TablicaDynamiczna.cpp" Kruskal/kruskal_implementation.cpp Kruskal/kruskal_implementation.h Kruskal/set.cpp Kruskal/set.h Dijkstra/Dijkstra_implementation.cpp Dijkstra/Dijkstra_implementation.h Bellman-Ford/BelmanFord_implementation.cpp Bellman-Ford/BelmanFord_implementation.h Presentation/Presentation.cpp Presentation/Presentation.h Times/Time_counter_graph_gen.cpp Times/Time_counter_graph_gen.h File_handling/Writer.cpp File_handling/Writer.h)
