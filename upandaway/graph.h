//		Klasse "Graph" Deklarationen
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <iomanip>
#include <cfloat>  // wg. MAXFLOAT
using namespace std;

const double noEdge = FLT_MAX;
const double weightBackEdge = -1.0;
const double weightCrossEdge = -2.0;
const double weightForwardEdge = -3.0;

enum VertexColor {
    WHITE = 0, GREY = 1, BLACK = 2
};

template <class T, int maxVertices>
class Graph {
private:
    class Vertex {
    public:
        Vertex() { // Konstruktor
            indegree = outdegree = ord = 0;
            living = false;
            color = WHITE;
            start = end = 0;
            predecessor = -1;
        }
        T value; // Daten des Knotens
        int indegree; // Eingangsgrad
        int outdegree; // Ausgangsgrad
        int ord; // Ordnungszahl des Knotens
        bool living; // Knoten existiert
        VertexColor color; //Farbcodierung für Bearbeitungszustand
        int start, end; //Start und Ende der Bearbeitungszeit für DFS
        int predecessor; //Für aufspannenden Baum
    };
    int numVertices; // Anzahl der Knoten eines Digraphen
    int numEdges; // Anzahl der Kanten eines Digraphen
    double edges[maxVertices][maxVertices]; // repraesentiert bewertete Kanten des Graphen
    Vertex vertices[maxVertices]; // repraesentiert Knoten des Digraphen
public:// Operationen auf dem Graphen
    Graph(); // Graphen generieren
    ~Graph(); // Graphen freigeben
    void insertVertex(int n, T m); // fuegt neuen Knoten n mit Markierung m ein
    void deleteVertex(int n); // entfernt Knoten n
    T getVertexValue(int n); // gibt Wert des Knoten n zurueck
    void setVertexValue(int n, T m); // Aendert Wert des Knoten n
    int firstVertex(); // Erster Knoten des Graphen
    int nextVertex(int n); // naechster Knoten nach n (-1 wenn keiner existiert)
    void insertEdge(int v, int w, double weight); // fuegt neue Kante (v,w) mit Gewicht weight ein
    void insertEdge(int v, int w); // fuegt neue Kante (v,w) mit Gewicht 0 ein
    void deleteEdge(int v, int w); // loescht Kante (v,w)
    int firstEdge(int v); // Erster Kante des Knoten v des Graphen
    int nextEdge(int v, int n); // naechste Kante des Knotens v nach n
    // (-1 wenn keiner existiert)
    bool isVisited(int n); // true, wenn Knoten n besucht, sonst false
    void setEdgeWeight(int v, int w, double weight); //aendert Kantengewicht
    bool isEdge(int v, int w); // existiert Kante (v,w)?
    double getEdge(int v, int w); // gibt Kantenbewertung  von (v,w) zurck
    int getNumVertices(); // Anzahl der Knoten
    int getMaxVertices(); // Max. Anzahl der Knoten
    int getNumEdges(); // Anzahl der Kanten
    int getIndegree(int n); // liefert Eingangsgrad eines Knotens
    int getOutdegree(int n); // liefert Ausgangsgrad eines Knotens
    int getColor(int n); //liefert Farbe des Knotens
    void setColor(int n, VertexColor color); // Knoten n als nicht besucht, besucht oder abgeschlossen markieren
    int getStart(int n); //liefert Startzeitpunkt
    void setStart(int n, int time); //Startzeitpunkt der Bearbeitung für DFS setzen
    int getEnd(int n); //liefert Endzeitpunkt
    void setEnd(int n, int time); //Endzeitpunkt der Bearbeitung für DFS setzen
    void setOrd(int v, int n); // Ordnungsnummer n im Knoten v setzen
    int getOrd(int v); // Ordnungsnummer des Knotens v liefern
    int getPredecessor(int n); //liefert Vorgaengerknoten
    void setPredecessor(int n, int pre); //Vorgängerknoten setzen
    void printVertex(int n); // Ausgabe des Knotens n eines Graphen
    void printVertices(); // Ausgabe aller Knotens  eines Graphen
    void printAdjMatrix(); // Adjazenzmatrix ausgeben
    void deleteGraph(); // alle Knoten und Kanten loeschen


};


template <class T, int maxVertices>
Graph<T, maxVertices>::Graph() {
    numVertices = numEdges = 0;
    for (int i = 0; i < maxVertices; i++)
        for (int j = 0; j < maxVertices; j++)
            edges[i][j] = noEdge;
}

template <class T, int maxVertices>
Graph<T, maxVertices>::~Graph() {
    ;
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::insertVertex(int n, T m) {
    if (n >= 0 && n < maxVertices) {
        Vertex v = vertices[n];
        vertices[n].living = true;
        vertices[n].value = m;
    }
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::firstVertex() {
    for (int i = 0; i < maxVertices; i++)
        if (vertices[i].living == true)
            return i;
    return -1;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::nextVertex(int n) { // nächster Knoten nach n (-1 wenn n der letzte ist)
    if (n < 0 || n > maxVertices - 2) return -1;
    for (int i = n + 1; i < maxVertices; i++)
        if (vertices[i].living == true)
            return i;
    return -1;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::firstEdge(int v) {
    if (vertices[v].living == true)
        for (int i = 0; i < maxVertices; i++)
            if (isEdge(v, i))
                return i;
    return -1;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::nextEdge(int v, int n) {
    if (vertices[v].living == true)
        for (int i = n + 1; i < maxVertices; i++)
            if (isEdge(v, i))
                return i;
    return -1;
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::deleteVertex(int n) {
    if (n >= 0 && n < maxVertices) {
        vertices[n].living = false;
        vertices[n].color = WHITE;
        vertices[n].value = vertices[n].ord = vertices[n].start =
                vertices[n].end = vertices[n].indegree =
                vertices[n].outdegree = vertices[n].predecessor = 0;
    }
    for (int i = 0; i < maxVertices; i++) {
        //  Vorhandene Kanten zum Knoten löschen
        edges[i][n] = noEdge;
        edges[n][i] = noEdge;
    }
}

template <class T, int maxVertices>
T Graph<T, maxVertices>::getVertexValue(int n) {
    if (n >= 0 && n < maxVertices && vertices[n].living) {
        return vertices[n].value;
    }
    return nullptr;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::getOrd(int n) {
    if (n >= 0 && n < maxVertices && vertices[n].living) {
        return vertices[n].ord;
    }
    return -1;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::getPredecessor(int n) {
    return vertices[n].predecessor;
}

template <class TV, int maxNodes>
void Graph<TV, maxNodes>::setPredecessor(int n, int pre) {
    vertices[n].predecessor = pre;
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::setOrd(int n, int o) {
    if (n >= 0 && n < maxVertices && vertices[n].living) {
        vertices[n].ord = o;
    }
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::setVertexValue(int n, T m) {
    if (n >= 0 && n < maxVertices && vertices[n].living) {
        vertices[n].value = m;
    }
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::getMaxVertices() {
    return maxVertices;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::getColor(int n) {
    return vertices[n].color;
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::setColor(int n, VertexColor color) {
    if (n >= 0 && n < maxVertices && vertices[n].living)
        vertices[n].color = color;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::getStart(int n) {
    return vertices[n].start;
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::setStart(int n, int time) {
    if (n >= 0 && n < maxVertices && vertices[n].living)
        vertices[n].start = time;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::getEnd(int n) {
    return vertices[n].end;
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::setEnd(int n, int time) {
    if (n >= 0 && n < maxVertices && vertices[n].living)
        vertices[n].end = time;
}

template <class T, int maxVertices>
bool Graph<T, maxVertices>::isVisited(int n) {
    if (n >= 0 && n < maxVertices && vertices[n].living) {
        return vertices[n].color;
    }
    return false;
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::insertEdge(int v, int w, double weight) {
    if (v >= 0 && v < maxVertices && w >= 0 && w < maxVertices && vertices[v].living && vertices[w].living && weight >= 0) {
        edges[v][w] = weight;
        vertices[v].outdegree++;
        vertices[v].ord++;
        vertices[w].indegree++;
        vertices[w].ord++;
    }
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::insertEdge(int v, int w) {
    insertEdge(v, w, 0);
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::deleteEdge(int v, int w) {
    if (v >= 0 && v < maxVertices && w >= 0 && w < maxVertices && vertices[v].living && vertices[w].living) {
        edges[v][w] = noEdge;
        vertices[v].outdegree--;
        vertices[v].ord--;
        vertices[w].indegree--;
        vertices[w].ord--;
    }
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::setEdgeWeight(int v, int w, double weight) {
    edges[v][w] = weight;
}

template <class T, int maxVertices>
bool Graph<T, maxVertices>::isEdge(int v, int w) {
    if (v >= 0 && v < maxVertices && w >= 0 && w < maxVertices)
        return edges[v][w] != noEdge;
    return false;
}

template <class TV, int maxVertices>
double Graph<TV, maxVertices>::getEdge(int v, int w) {
    if (isEdge(v, w))
        return edges[v][w];
    return noEdge;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::getNumEdges() {
    return numEdges;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::getNumVertices() {
    return numVertices;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::getIndegree(int n) {
    return vertices[n].indegree;
}

template <class T, int maxVertices>
int Graph<T, maxVertices>::getOutdegree(int n) {
    return vertices[n].outdegree;
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::printVertices() {
    cout << "Knoten:" << endl;
    for (int i = 0; i < maxVertices; i++) {
        printVertex(i);
    }
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::printVertex(int n) {
    string color;
    if (vertices[n].living){
        if (getColor(n) == 0)
            color = "WHITE";
        else if (getColor(n) == 1)
            color = "GREY";
        else
            color = "BLACK";
    }
    cout << "Nummer: " << n << " Wert: " << getVertexValue(n) << " Ordnung: " << getOrd(n)
         << " Farbe: " << setw(6) << color << " Start: " << getStart(n) << " Ende: " << getEnd(n)
         << " Vorgaenger: " << getPredecessor(n) << endl;
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::printAdjMatrix() {
    cout << "Adjazenz Matrix:" << endl;
    cout << "    ";
    for (int i = 1; i < maxVertices; i++)
        cout << setw(5) << i << " ";
    cout << "\n  --";
    for (int i = 1; i < maxVertices; i++)
        cout << "------";
    cout << endl;
    for (int i = 1; i < maxVertices; i++) {
        cout << "  " << i << "|";
        for (int j = 1; j < maxVertices; j++) {
            if (isEdge(i, j))
                cout << setw(5) << getEdge(i, j) << " ";
            else
                cout << setw(5) << "-" << " ";
        }
        cout << endl;
    }
}

template <class T, int maxVertices>
void Graph<T, maxVertices>::deleteGraph() {
    for (int i = 0; i < maxVertices; i++)
        deleteVertex(i);
    for (int i = 0; i < maxVertices; i++)
        for (int j = 0; j < maxVertices; j++)
            deleteEdge(i, j);
}
#endif
