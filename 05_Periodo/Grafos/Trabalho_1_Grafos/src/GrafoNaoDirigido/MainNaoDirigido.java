package GrafoNaoDirigido;

public class MainNaoDirigido {
    public static void main(String[] args){
        GrafoNaoDirigido<String> grafo = new GrafoNaoDirigido<String>();
        grafo.adicionaVertice("Joao");
        grafo.adicionaVertice("Lorenzo");
        grafo.adicionaVertice("Creuza");
        grafo.adicionaVertice("Creber");
        grafo.adicionaVertice("Craudio");

        grafo.adicionaAresta("Joao", "Lorenzo", 2.0);
        grafo.adicionaAresta("Lorenzo", "Creber", 3.0);
        grafo.adicionaAresta("Creber", "Creuza", 1.0);
        grafo.adicionaAresta("Joao", "Creuza", 1.0);
        grafo.adicionaAresta("Craudio", "Lorenzo", 2.0);
        grafo.adicionaAresta("Craudio", "Joao", 2.0);

        grafo.buscaLargura("Joao");
    }
}
