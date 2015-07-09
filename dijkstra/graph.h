#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define INFINITY_DIST 9999

// forward declare so it can be used before definition
typedef struct VertexStruct Vertex;

// defines adjacent vertices and their distance
typedef struct {
    // distance from the vertex that is adjacent
    uint32_t distance;
    // reference to the actual vertex this represents
    Vertex* vertex;
} AdjVertex;

// defines a single vertex
struct VertexStruct {
    // vertex value
    char value;
    // whether or not when parsing the graph the vertex has been visited
    bool isVisited;
    // total distance from the starting vertex
    uint32_t pathDistance;
    // list of adjacent vertices
    std::vector<AdjVertex>* adjVertices;

    // reference to the previous vertex of the shortest path
    // this value is filled in as Dijkstra's executes
    Vertex* pathVertex;
};

std::vector<Vertex*> buildGraph()
{
    printf("Building graph...\n");

    std::vector<Vertex*> graphVector;

    Vertex* vertexA = (Vertex*)malloc(sizeof(Vertex));
    memset(vertexA, 0, sizeof(Vertex));
    graphVector.push_back(vertexA);
    Vertex* vertexB = (Vertex*)malloc(sizeof(Vertex));
    memset(vertexB, 0, sizeof(Vertex));
    graphVector.push_back(vertexB);
    Vertex* vertexC = (Vertex*)malloc(sizeof(Vertex));
    memset(vertexC, 0, sizeof(Vertex));
    graphVector.push_back(vertexC);
    Vertex* vertexD = (Vertex*)malloc(sizeof(Vertex));
    memset(vertexD, 0, sizeof(Vertex));
    graphVector.push_back(vertexD);
    Vertex* vertexE = (Vertex*)malloc(sizeof(Vertex));
    memset(vertexE, 0, sizeof(Vertex));
    graphVector.push_back(vertexE);

    AdjVertex adjVertex;

    // VERTEX A
    vertexA->value = 'A';
    vertexA->isVisited = false;
    vertexA->pathDistance = INFINITY_DIST;
    vertexA->adjVertices = new std::vector<AdjVertex>();

    adjVertex.vertex = vertexB;
    adjVertex.distance = 3;
    vertexA->adjVertices->push_back(adjVertex);

    adjVertex.vertex = vertexD;
    adjVertex.distance = 7;
    vertexA->adjVertices->push_back(adjVertex);

    // VERTEX B
    vertexB->value = 'B';
    vertexB->isVisited = false;
    vertexB->pathDistance = INFINITY_DIST;
    vertexB->adjVertices = new std::vector<AdjVertex>();

    adjVertex.vertex = vertexA;
    adjVertex.distance = 3;
    vertexB->adjVertices->push_back(adjVertex);

    adjVertex.vertex = vertexD;
    adjVertex.distance = 2;
    vertexB->adjVertices->push_back(adjVertex);

    adjVertex.vertex = vertexC;
    adjVertex.distance = 4;
    vertexB->adjVertices->push_back(adjVertex);

    // VERTEX C
    vertexC->value = 'C';
    vertexC->isVisited = false;
    vertexC->pathDistance = INFINITY_DIST;
    vertexC->adjVertices = new std::vector<AdjVertex>();

    adjVertex.vertex = vertexB;
    adjVertex.distance = 4;
    vertexC->adjVertices->push_back(adjVertex);

    adjVertex.vertex = vertexD;
    adjVertex.distance = 5;
    vertexC->adjVertices->push_back(adjVertex);

    adjVertex.vertex = vertexE;
    adjVertex.distance = 6;
    vertexC->adjVertices->push_back(adjVertex);

    // VERTEX D
    vertexD->value = 'D';
    vertexD->isVisited = false;
    vertexD->pathDistance = INFINITY_DIST;
    vertexD->adjVertices = new std::vector<AdjVertex>();

    adjVertex.vertex = vertexA;
    adjVertex.distance = 7;
    vertexD->adjVertices->push_back(adjVertex);

    adjVertex.vertex = vertexB;
    adjVertex.distance = 2;
    vertexD->adjVertices->push_back(adjVertex);

    adjVertex.vertex = vertexC;
    adjVertex.distance = 5;
    vertexD->adjVertices->push_back(adjVertex);

    adjVertex.vertex = vertexE;
    adjVertex.distance = 4;
    vertexD->adjVertices->push_back(adjVertex);

    // VERTEX E
    vertexE->value = 'E';
    vertexE->isVisited = false;
    vertexE->pathDistance = INFINITY_DIST;
    vertexE->adjVertices = new std::vector<AdjVertex>();

    adjVertex.vertex = vertexC;
    adjVertex.distance = 6;
    vertexE->adjVertices->push_back(adjVertex);

    adjVertex.vertex = vertexD;
    adjVertex.distance = 4;
    vertexE->adjVertices->push_back(adjVertex);

    return graphVector;
}

void printGraph(std::vector<Vertex*> graphVector) {

    for(unsigned int i = 0; i < graphVector.size(); i++)
    {
        printf("%c: ", graphVector[i]->value);
        for(unsigned int j = 0; j < graphVector[i]->adjVertices->size(); j++)
        {
            printf("%c,%d ", (*(graphVector[i]->adjVertices))[j].vertex->value, (*(graphVector[i]->adjVertices))[j].distance);
        }
        printf("\n");
    }
    printf("\n");
}
