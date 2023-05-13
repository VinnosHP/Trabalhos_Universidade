package GrafoDirigido;

import java.util.ArrayList;

public class Vertice<T> {
    private T dado;
    private ArrayList<Arco<T>> arcosSaida;
    private ArrayList<Arco<T>> arcosEntrada;

    public Vertice(T dado){
        this.dado = dado;
        this.arcosSaida = new ArrayList<Arco<T>>();
        this.arcosEntrada = new ArrayList<Arco<T>>();
    }

    public T getDado() { return dado; }
    public void setDado(T dado) { this.dado = dado; }
    public void adicionaArcoEntrada(Arco<T> arco){ this.arcosEntrada.add(arco); }
    public void adicionaArcoSaida(Arco<T> arco){ this.arcosSaida.add(arco); }
    public ArrayList<Arco<T>> getArcosSaida() { return arcosSaida; }
    public ArrayList<Arco<T>> getArcosEntrada() { return arcosEntrada; }
}
