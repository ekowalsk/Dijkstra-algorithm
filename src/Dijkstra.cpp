#include <limits.h>
#include <iostream>

#include "Dijkstra.h"

Dijkstra::Dijkstra(Graph pGraph): graph(pGraph){
    initState();
}

void Dijkstra::initState(){
    predecessors = new std::unordered_map<int, int>();
    distances = new std::unordered_map<int, int>();
    for (auto it = graph.edges->begin(); it != graph.edges->end(); it++){
        if (predecessors->find(it->first) == predecessors->end())
            predecessors->insert(std::make_pair(it->first, INT_MIN));
    }
}

void Dijkstra::shortest_path(int source, int destination){
    calculate_shortest_path(source, destination);
    if (destination != INT_MIN) {
        printPath(reconstructPath(source, destination));
        std::cout << "distance: " << distances->at(destination) << std::endl;
    }
}

void Dijkstra::calculate_shortest_path(int source, int destination){
    if (!isValidVertex(source) || (!isValidVertex(destination) && destination != INT_MIN)){
        std::cerr << "Invalid source or destination vertex. " << std::endl;
        exit(-1);
    }
    clearState();
    updateDistance(source, 0);
    auto priorityQueue = createPriorityQueue();
    int currentVertex = source;
    while (!priorityQueue->empty()) {
        if (source == destination)
            break;
        updateSuccessorsDistances(currentVertex);
        currentVertex = popPriorityQueue(priorityQueue);
    }
}

std::list<int> * Dijkstra::createPriorityQueue() {
    auto priorityQueue = new std::list<int>();
    for (auto & predecessor : *predecessors)
        priorityQueue->push_back(predecessor.first);
    return priorityQueue;
}

bool Dijkstra::isValidVertex(int vertex){
    return predecessors->find(vertex) != predecessors->end();
}

void Dijkstra::clearState(){
    for (auto & predecessor : *predecessors){
        predecessor.second = INT_MIN;
        distances->insert(std::make_pair(predecessor.first, INT_MAX));
    }
}

void Dijkstra::updateDistance(int vertex, int distance){
    distances->find(vertex)->second = distance;
}

int Dijkstra::popPriorityQueue(std::list<int> * priorityQueue){
    int minVertex = *(priorityQueue->begin());
    auto minIterator = priorityQueue->begin();
    int minDistance = distances->find(minVertex)->second;
    for (auto element  = priorityQueue->begin(); element != priorityQueue->end(); element++){
        if (minDistance > distances->find(*element)->second){
            minDistance = distances->find(*element)->second;
            minVertex = *element;
            minIterator = element;
        }
    }
    priorityQueue->erase(minIterator);
    return minVertex;
}

void Dijkstra::updateSuccessorsDistances(int predecessor){
    auto successorsEdges = graph.getOutgoingEdges(predecessor);
    for (auto & successor : successorsEdges->second){
        /* graph.getOutgoingEdges(currentVertex) can return edges, that have already been deleted from priority queue */
        try{
            if (getDistance(successor.getDestination()) > getDistance(predecessor) + successor.getWeight()) {
                updateDistance(successor.getDestination(), getDistance(predecessor) + successor.getWeight());
                updatePredecessors(successor.getDestination(), predecessor);
            }
        } catch (const std::out_of_range& e){
            continue;
        }
    }
}

int Dijkstra::getDistance(int vertex){
    return distances->find(vertex)->second;
}

std::list<int> Dijkstra::reconstructPath(int source, int destination){
    std::list<int> path = std::list<int>();
    int currentVertex = destination;
    while(currentVertex != source){
        if (currentVertex == INT_MIN)
            handleNoConnection(source, destination);
        path.push_front(currentVertex);
        currentVertex = predecessors->find(currentVertex)->second;
    }
    path.push_front(source);
    return path;
}

void Dijkstra::handleNoConnection(int source, int destination){
    std::cerr << "connection between " << source << " and " << destination << " does not exist " << std::endl;
    exit(1);
}

void Dijkstra::printPath(const std::list<int>& path){
    std::string pathString;
    for (int it : path)
        pathString += std::to_string(it) + " -> ";
    std::cout << "Dijkstra shortest path: " << pathString << std::endl;
}

void Dijkstra::updatePredecessors(int vertex, int predecessor){
    predecessors->find(vertex)->second = predecessor;
}

void Dijkstra::getPath(int source, int destination){
    printPath(reconstructPath(source, destination));
    std::cout << "distance: " << distances->find(destination)->second << std::endl;
}


Dijkstra::~Dijkstra(){
    delete distances;
    delete predecessors;
}



