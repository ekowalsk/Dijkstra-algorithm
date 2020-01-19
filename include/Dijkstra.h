#ifndef GIS_DIJKSTRA_H
#define GIS_DIJKSTRA_H

#include <limits.h>
#include <chrono>

#include "Graph.h"

/* Klasa zawiera metody oraz struktury danych niezbędne do wykonania algorytmu Dijkstry */
/* distances - zawiera odegłości (koszty przejścia) od wierzchołka startowego do poszczególnych wierzchołków */
/* predecessors - zawiera poprzedniki poszczególnych wierzchołków */

class Dijkstra {

private:
    Graph graph;
    std::unordered_map<int, int> * distances{};
    std::unordered_map<int, int> * predecessors{};

    /* Inicjuje struktury danych podczas tworzenia obiektu */
    void initState();
    /* Czyści struktury danych przed każdym wywołaniem algorytmu na tym samym obiekcie klasy Dijkstra */
    void clearState();
    /* Tworzy początkową kolejkę priorytetową wierzchołków */
    std::list<int> * createPriorityQueue();

    /* Sprawdza, czy wierzchołek startowy i docelowy znajdują się w grafie */
    bool isValidVertex(int vertex);

    /* Wybiera z kolejki wierzchołek o najmniejszej odległości od wierzchołka startowego */
    int popPriorityQueue(std::list<int> * priorityQueue);

    /* Ustawia dystans dla wierzchołka vertex na wartość distance */
    void updateDistance(int vertex, int distance);
    /* Sprawdza dla następników wierzchołka vertex, czy przejście z wierzchołka vertex do danego następnika jest tańsze
     * niż aktualny koszt przejścia do następnika i jeżeli tak - aktualizuje koszt przejścia */
    void updateSuccessorsDistances(int vertex);
    /* Ustawia poprzednika dla wierzchołka vertex */
    void updatePredecessors(int vertex, int predecessor);

    /* Zwraca ze struktury distances dystans od wierzchołka startowego do wierzchołka vertex*/
    int getDistance(int vertex);
    /* Zwraca ze struktury predecessors poprzednika dla wierzchołka vertex*/
    int getPredecessor(int vertex);

    /* Rekonstruuje najtańszą ścieżkę pomiędzy wierzchołkiem startowym a końcowym na podstawie zawartości struktury
     * predecessors*/
    bool reconstructPath(int source, int destination, std::list<int> * path);
    /* Oblicza najtańszą ścieżkę */
    double calculateShortestPath(int source, int destination);
    /* Wyświetla ścieżkę */
    static void printPath(const std::list<int>& path);
    /* W razie wykrycia braku ścieżki od wierzchołka startowego do wierzchołka końcowego wypisuje komunikat błędu
     * na standardowe wyjście błędu oraz kończy działanie programu */
    static void handleNoConnection(int source, int destination);
public:
    explicit Dijkstra(const Graph& pGraph);
    ~Dijkstra();
    /* oblicza najtańszą ścieżkę od wierzchołka source do wierzchołka destination (jeżeli podany), jeżeli nie -
     * oblicza najtańsze ścieżki z wierzchołka source do pozostałych wierzchołków. Rekontruuje ścieżkę oraz
     * wyświetla wyniki */
    void shortestPath(int source, int destination = INT_MIN);

    /* na podstawie struktur po wykonaniu algorytmu odtwarza najkrótszą ścieżkę pomiędzy wierzchołkiem startowym
     * a początkowym*/
    void getPath(int source, int destination);
};
#endif //GIS_DIJKSTRA_H
