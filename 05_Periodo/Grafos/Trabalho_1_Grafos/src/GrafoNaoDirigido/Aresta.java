package GrafoNaoDirigido;

public class Aresta<T> {

    private double peso;
    private Vertice<T> a; // Aqui ao inves de Fim e Inicio tem Vertice A e Vertice B ja que nao existe direção fixa na aresta.
    private Vertice<T> b;

    public Aresta(double peso, Vertice<T> a, Vertice<T> b) {
        this.peso = peso;
        this.a = a;
        this.b = b;
    }

    public Double getPeso() { return peso; }
    public void setPeso(double peso) { this.peso = peso; }
    public Vertice<T> getA() { return a; }
    public void setA(Vertice<T> a) { this.a = a; }
    public Vertice<T> getB() { return b; }
    public void setB(Vertice<T> b) { this.b = b; }
}
