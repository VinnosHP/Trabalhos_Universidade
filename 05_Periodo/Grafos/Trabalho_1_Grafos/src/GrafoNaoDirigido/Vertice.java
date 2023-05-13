package GrafoNaoDirigido;

import java.util.ArrayList;

public class Vertice<T> {
    private T dado;
    private ArrayList<Aresta<T>> arestas;

    public Vertice(T dado){
        this.dado = dado;
        this.arestas = new ArrayList<Aresta<T>>();
    }

    public T getDado() { return dado; }
    public void setDado(T dado) { this.dado = dado; }
    public void adicionaAresta(Aresta<T> aresta){ this.arestas.add(aresta); }
    public ArrayList<Aresta<T>> getArestas() { return arestas; }
}
