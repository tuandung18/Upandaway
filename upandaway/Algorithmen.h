#ifndef ALGORITHMEN_H
#define ALGORITHMEN_H
#include <iostream>
#include "graph.h"
#include <queue>	// wg. Bfs
using namespace std;

// Hilfsroutinen

template <class T, int maxVertices>
void setAllColor(Graph<T, maxVertices> &g, VertexColor color) { // Alle Knoten als besucht bzw unbesucht markieren
    int v = g.firstVertex();
    while (v != -1) {
        g.setColor(v, color);
        v = g.nextVertex(v);
    }
}

template <class T, int maxVertices>
void printVertex(Graph<T, maxVertices> &g, int n) { // Knoten n besuchen
    g.printVertex(n);
}

// Tiefensuche
template <class T, int maxVertices>
int dfs(Graph<T, maxVertices> &g, int v, int time) {// Tiefensuche ab Knoten v
    if (!g.isVisited(v)) {
        g.setColor(v, GREY); // als besucht markieren
        g.setStart(v, time); // Startzeitpunkt für Knoten setzen
        printVertex(g, v); // v besuchen
        int w = g.firstEdge(v);
        while (w != -1) { // alle Nachfolger von v bearbeiten
            if (!g.isVisited(w)) { // w noch nicht besucht
                time += 1;
                time = dfs(g, w, time); // Tiefensuche fuer w starten
            } else { //Kantenmarkierungen setzen
                if (g.getColor(w) == GREY)
                    g.setEdgeWeight(v, w, weightBackEdge); //Rückwärtskante
                else if (g.getColor(w) == BLACK) {
                    if (g.getStart(v) < g.getEnd(w))
                        g.setEdgeWeight(v, w, weightForwardEdge); // Forwardkante
                    else
                        g.setEdgeWeight(v, w, weightCrossEdge); //Crosskante
                }
            }
            w = g.nextEdge(v, w);
        }
        time += 1;
        g.setColor(v, BLACK);
        g.setEnd(v, time);
        printVertex(g, v);
    }
    return time;
}

template <class T, int maxVertices>
void depthFirstSearch(Graph<T, maxVertices> &g) { // Tiefensuche
    int time = 1;
    setAllColor(g, WHITE); // Alle Knoten als unbesucht markieren
    int v = g.firstVertex();
    while (v != -1) {
        if (!g.isVisited(v)) { // v noch nicht besucht
            time = dfs(g, v, time); // Tiefensuche für v starten
            time += 1;
        }
        v = g.nextVertex(v);
    }
}

// Breitensuche
template <class T, int maxVertices>
void bfs(Graph<T, maxVertices> &g, int v) { // Breitensuche ab Knoten v
    queue<int> q; // Schlange zum Merken der besuchten Knoten
    if (!g.isVisited(v)) {
        g.setColor(v, GREY); // als besucht markieren
        printVertex(g, v); // v besuchen
        q.push(v); // Startknoten in Schlange einfuegen
        while (!q.empty()) { // Solange bis Schlange leer
            v = q.front(); // naechsten besuchten Knoten aus Schlange lesen
            q.pop(); // und aus Schlange entfernen
            int w = g.firstEdge(v); // erste von v ausgehende Kante
            while (w != -1) { // für alle Nachfolger von v
                if (!g.isVisited(w)) { // w noch nicht besucht
                    g.setColor(w, GREY); // als besucht markieren
                    g.setPredecessor(w, v);
                    printVertex(g, w); // w ausgeben
                    q.push(w); // w in Schlange ablegen
                }
                w = g.nextEdge(v, w); // naechste Kante (v,w)
            }
            g.setColor(v, BLACK);
            printVertex(g, v);
        }
    }
}

template <class T, int maxVertices>
void breadthFirstSearch(Graph<T, maxVertices> &g) { // Breitensuche
    setAllColor(g, WHITE); // Alle Knoten als unbesucht markieren
    int v = g.firstVertex();
    while (v != -1) {
        if (!g.isVisited(v)) // v noch nicht besucht
            bfs(g, v); // Breitensuche fuer v starten
        v = g.nextVertex(v);
    }
}




#endif // ALGORITHMEN_H
