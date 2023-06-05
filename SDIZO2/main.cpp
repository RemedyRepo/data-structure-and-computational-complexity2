#include <iostream>
#include "Graph_tools/Matrix.h"
#include "Prim/prim_implementation.h"
#include "Graph_tools/Structures/Kopiec Binarny/KopiecBinarny.h"
#include "Kruskal/kruskal_implementation.h"
#include "Dijkstra/Dijkstra_implementation.h"
#include "Bellman-Ford/BelmanFord_implementation.h"
#include "Presentation/Presentation.h"
#include "Times/Time_counter_graph_gen.h"


int main() {
    int gate = 0;
    Writer *writer = new Writer();
    Presentation *presenation = new Presentation();
    Time_counter_graph_gen *gen = new Time_counter_graph_gen();
    while(gate != 6){
     std::cout << "=====SDIZO PROJECT 2=====" << std::endl;
     std::cout << "\n";
     std::cout << "Choose the algorithm you want to test: \n";
     std::cout << "1 - Prim Algorithm \n";
     std::cout << "2 - Kruskal Algorithm \n";
     std::cout << "3 - Dijkstra Algorithm \n";
     std::cout << "4 - Bellman-Ford Algorithm \n";
     std::cout << "5 - Time testing iterface \n";
     std::cout << "6 - exit \n";
     std::cin >> gate;
     switch(gate){
         case 1:
             presenation->prim();
             break;
         case 2:
             presenation->kruskal();
             break;
         case 3:
             presenation->dijkstra();
             break;
         case 4:
             presenation->bellman_ford();
             break;
         case 5:
             for(int i = 0; i < 5; i++){
                 writer->save(("Prim-matrix" + std::to_string(100+i*50) + " . density 0.25 - 0.99"));
                 gen->test_prim_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.25);
                 gen->test_prim_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.50);
                 gen->test_prim_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.75);
                 gen->test_prim_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.99);
                 writer->save(("Prim-list" + std::to_string(100+i*50) + " . density 0.25 - 0.99"));
                 gen->test_prim_list(100,"graph",100+i*50,0,(100+i*50)-1,0.25);
                 gen->test_prim_list(100,"graph",100+i*50,0,(100+i*50)-1,0.50);
                 gen->test_prim_list(100,"graph",100+i*50,0,(100+i*50)-1,0.75);
                 gen->test_prim_list(100,"graph",100+i*50,0,(100+i*50)-1,0.99);
                 writer->save(("Dijkstra-matrix" + std::to_string(100+i*50) + " . density 0.25 - 0.99"));
                 gen->test_Dijkstra_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.25);
                 gen->test_Dijkstra_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.50);
                 gen->test_Dijkstra_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.75);
                 gen->test_Dijkstra_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.99);
                 writer->save(("Dijkstra-list" + std::to_string(100+i*50) + " . density 0.25 - 0.99"));
                 gen->test_Dijkstra_list(100,"graph",100+i*50,0,(100+i*50)-1,0.25);
                 gen->test_Dijkstra_list(100,"graph",100+i*50,0,(100+i*50)-1,0.50);
                 gen->test_Dijkstra_list(100,"graph",100+i*50,0,(100+i*50)-1,0.75);
                 gen->test_Dijkstra_list(100,"graph",100+i*50,0,(100+i*50)-1,0.99);
                 writer->save(("BellmanFord-matrix" + std::to_string(100+i*50) + " . density 0.25 - 0.99"));
                 gen->test_BellmanFord_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.25);
                 gen->test_BellmanFord_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.50);
                 gen->test_BellmanFord_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.75);
                 gen->test_BellmanFord_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.99);
                 writer->save(("BellmanFord-list" + std::to_string(100+i*50) + " . density 0.25 - 0.99"));
                 gen->test_BellmanFord_list(100,"graph",100+i*50,0,(100+i*50)-1,0.25);
                 gen->test_BellmanFord_list(100,"graph",100+i*50,0,(100+i*50)-1,0.50);
                 gen->test_BellmanFord_list(100,"graph",100+i*50,0,(100+i*50)-1,0.75);
                 gen->test_BellmanFord_list(100,"graph",100+i*50,0,(100+i*50)-1,0.99);
                 writer->save(("Kruskal-matrix" + std::to_string(100+i*50) + " . density 0.25 - 0.99"));
                 gen->test_kruskal_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.25);
                 gen->test_kruskal_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.50);
                 gen->test_kruskal_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.75);
                 gen->test_kruskal_matrix(100,"graph",100+i*50,0,(100+i*50)-1,0.99);
                 writer->save(("Kruskal-list" + std::to_string(100+i*50) + " . density 0.25 - 0.99"));
                 gen->test_krusal_list(100,"graph",100+i*50,0,(100+i*50)-1,0.25);
                 gen->test_krusal_list(100,"graph",100+i*50,0,(100+i*50)-1,0.50);
                 gen->test_krusal_list(100,"graph",100+i*50,0,(100+i*50)-1,0.75);
                 gen->test_krusal_list(100,"graph",100+i*50,0,(100+i*50)-1,0.99);
             }
             break;
     }
    }
}
