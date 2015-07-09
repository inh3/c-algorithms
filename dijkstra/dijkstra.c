#include "graph.h"

void dijkstra(std::vector<Vertex*> graphVector);
Vertex* getMinDistanceVertex(std::vector<Vertex*>& graphVector);
void printPath(Vertex* destVertex);

int main() {

    printf("DIJKSTRA: A to E\n\n");

    std::vector<Vertex*> graphVector = buildGraph();
    printGraph(graphVector);

    // set the A vertex to have 0 distance and its previous vertex to NULL
    graphVector[0]->pathDistance = 0;
    graphVector[0]->pathVertex = NULL;

    dijkstra(graphVector);
    printf("SHORTEST PATH: %u\n", graphVector[4]->pathDistance);
    printPath(graphVector[4]);
    printf("\n");

    return 0;
}

void printPath(Vertex* destVertex) {

    if(destVertex->pathVertex != NULL) {
        printPath(destVertex->pathVertex);
        printf(" to ");
    }

    printf("%c", destVertex->value);
};

void dijkstra(std::vector<Vertex*> graphVector) {

    // if there are still vertices to process
    while(!graphVector.empty()) {

        // get the vertex with the minimum overall path distance and mark it as visited
        Vertex* minVertex = getMinDistanceVertex(graphVector);
        minVertex->isVisited = true;

        // get all the adjacent vertices
        std::vector<AdjVertex> adjVertices = *(minVertex->adjVertices);

        // for each adjacent vertex
        for(uint32_t i = 0; i < adjVertices.size(); i++) {

            AdjVertex adjVertex = adjVertices[i];

            // if its been already visited then we know it is already at its minimum
            if(!adjVertex.vertex->isVisited) {

                // calculate the new possible path distance
                uint32_t pathDistance = minVertex->pathDistance + adjVertex.distance;

                // if it is actually smaller than before then update it and update the path
                if(pathDistance < adjVertex.vertex->pathDistance) {
                    adjVertex.vertex->pathDistance = pathDistance;
                    adjVertex.vertex->pathVertex = minVertex;
                }
            }
        }
    }
}

Vertex* getMinDistanceVertex(std::vector<Vertex*>& graphVector) {

    uint32_t minDistance = INFINITY_DIST;
    uint32_t vertexIndex = -1;
    Vertex* minVertex = NULL;

    // find the vertex that has the smallest distance from start
    //
    // the first iteration will be the starting vertex because it has
    // its path distance set to 0
    for(uint32_t i = 0; i < graphVector.size(); i++) {
        if(graphVector[i]->pathDistance < minDistance) {
            minVertex = graphVector[i];
            minDistance = graphVector[i]->pathDistance;
            vertexIndex = i;
        }
    }

    // remove the vertex because it is about to be processed
    if(minVertex) {
        graphVector.erase(graphVector.begin() + vertexIndex);
    }

    return minVertex;
}
