#include <limits.h>
#include <iostream>

#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph pGraph): graph(pGraph){
    initState();
}

void Dijkstra::initState(){
    predecessors = new std::map<int, int>();
    priorityQueue = new std::map<int, int>();
    for (auto it = graph.edges->begin(); it != graph.edges->end(); it = graph.edges->upper_bound(it->first))
        predecessors->insert(std::make_pair(it->first, NULL));
}

void Dijkstra::shortest_path(int source, int destination){
    printPath(calculate_shortest_path(source, destination));
    std::cout << "distance: " << priorityQueue->at(destination) << std::endl;
}

std::list<int> Dijkstra::calculate_shortest_path(int source, int destination){
    if (!isValidVertex(source) || !isValidVertex(destination)){
        std::cerr << "Invalid source or destination vertex. " << std::endl;
        exit(-1);
    }
    clearState();
    updateDistance(source, 0);
    int currentVertex = peekPriorityQueue();
    while (currentVertex != destination) {
        updateSuccessorsDistances(currentVertex);
        eraseFromPriorityQueue(currentVertex);
        currentVertex = peekPriorityQueue();
    }
    return reconstructPath(source, destination);
}

bool Dijkstra::isValidVertex(int vertex){
    return predecessors->find(vertex) != predecessors->end();
}

void Dijkstra::clearState(){
    for (auto & predecessor : *predecessors){
        predecessor.second = NULL;
        priorityQueue->insert(std::make_pair(predecessor.first, INT_MAX));
    }
}

void Dijkstra::updateDistance(int vertex, int distance){
    priorityQueue->at(vertex) = distance;
}

int Dijkstra::peekPriorityQueue(){
    int minDistance = priorityQueue->begin()->second;
    int minVertex = priorityQueue->begin()->first;
    for (auto & element : *priorityQueue){
        if (minDistance > element.second){
            minDistance = element.second;
            minVertex = element.first;
        }
    }
    return minVertex;
}

void Dijkstra::updateSuccessorsDistances(int predecessor){
    auto successors = graph.getOutgoingEdges(predecessor);
    for (auto successor = successors.first; successor != successors.second; successor++){
        /* graph.getOutgoingEdges(currentVertex) can return edges, that have already been deleted from priority queue */
        try{
            if (getDistance(successor->second.getDestination()) > getDistance(predecessor) + successor->second.getWeight()) {
                updateDistance(successor->second.getDestination(), getDistance(predecessor) + successor->second.getWeight());
                updatePredecessors(successor->second.getDestination(), predecessor);
            }
        } catch (const std::out_of_range& e){
            continue;
        }
    }
}

int Dijkstra::getDistance(int vertex){
    return priorityQueue->at(vertex);
}
void Dijkstra::eraseFromPriorityQueue(int vertex){
    priorityQueue->erase(vertex);
}

std::list<int> Dijkstra::reconstructPath(int source, int destination){
    std::list<int> path = std::list<int>();
    path.push_back(destination);
    int currentVertex = predecessors->at(destination);
    while(currentVertex != source){
        path.push_front(currentVertex);
        currentVertex = predecessors->at(currentVertex);
    }
    path.push_front(source);
    return path;
}

void Dijkstra::printPath(const std::list<int>& path){
    std::string pathString;
    for (int it : path)
        pathString += std::to_string(it) + " -> ";
    std::cout << "Dijkstra shortest path: " << pathString << std::endl;
}

void Dijkstra::updatePredecessors(int vertex, int predecessor){
    predecessors->at(vertex) = predecessor;
}

Dijkstra::~Dijkstra(){
    delete priorityQueue;
    delete predecessors;
}



