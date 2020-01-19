#include <limits.h>
#include <iostream>

#include "Dijkstra.h"

Dijkstra::Dijkstra(const Graph& pGraph): graph(pGraph){
    initState();
}

void Dijkstra::initState(){
    predecessors = new std::unordered_map<int, int>();
    distances = new std::unordered_map<int, int>();
    for (auto & edge : *graph.edges){
        if (predecessors->find(edge.first) == predecessors->end())
            predecessors->insert(std::make_pair(edge.first, INT_MIN));
    }
}

void Dijkstra::shortestPath(int source, int destination){
    double elapsed_seconds = calculateShortestPath(source, destination);
    std::cout << "czas obliczeń: " << elapsed_seconds <<  " sekund" << std::endl;
    if (destination != INT_MIN)
        getPath(source, destination);
    else {
        for (auto &vertex : *distances)
            if (vertex.first != source)
               getPath(source, vertex.first);
    }
}

double Dijkstra::calculateShortestPath(int source, int destination){
    if (!isValidVertex(source) || (!isValidVertex(destination) && destination != INT_MIN)){
        std::cerr << "Invalid source or destination vertex. " << std::endl;
        exit(-1);
    }
    clearState();
    auto start = std::chrono::steady_clock::now();
    updateDistance(source, 0);
    auto priorityQueue = createPriorityQueue();
    int currentVertex = popPriorityQueue(priorityQueue);
    while (!priorityQueue->empty() && getDistance(currentVertex) != INT_MAX) {
        if (source == destination)
            break;
        updateSuccessorsDistances(currentVertex);
        currentVertex = popPriorityQueue(priorityQueue);
    }
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::duration<double> >(end - start).count();
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
    int minDistance = getDistance(minVertex);
    for (auto element  = priorityQueue->begin(); element != priorityQueue->end(); element++){
        if (minDistance > getDistance(*element)){
            minDistance = getDistance(*element);
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

bool Dijkstra::reconstructPath(int source, int destination, std::list<int> * path){
    int currentVertex = destination;
    while(currentVertex != source){
        if (currentVertex == INT_MIN)
            return false;
        path->push_front(currentVertex);
        currentVertex = getPredecessor(currentVertex);
    }
    path->push_front(source);
    return true;
}

int Dijkstra::getPredecessor(int vertex){
    return predecessors->find(vertex)->second;
}

void Dijkstra::handleNoConnection(int source, int destination){
    std::cout << "connection between " << source << " and " << destination << " does not exist " << std::endl;
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
    std::list<int> path = std::list<int>();
    if (reconstructPath(source, destination, &path)) {
        printPath(path);
        std::cout << "distance: " << distances->find(destination)->second << std::endl;
    } else
        handleNoConnection(source, destination);
}


Dijkstra::~Dijkstra(){
    delete distances;
    delete predecessors;
}



