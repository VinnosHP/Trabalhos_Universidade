package GrafoNaoDirigido;

import java.util.ArrayList;

public class GrafoNaoDirigido<T>{

    private ArrayList<Vertice<T>> vertices;
    private ArrayList<Aresta<T>> arestas;

    public GrafoNaoDirigido(){
        this.vertices = new ArrayList<Vertice<T>>();
        this.arestas = new ArrayList<Aresta<T>>();
    }

    public void adicionaVertice(T dado){
        Vertice<T> novoV = new Vertice<T>(dado);
        this.vertices.add(novoV);
    }

    public void adicionaAresta(T dadoA, T dadoB){
        Vertice<T> a = this.buscaVertice(dadoA);
        Vertice<T> b = this.buscaVertice(dadoB);
        Aresta<T> arco = new Aresta<T>(1.0,a,b);
        a.adicionaAresta(arco);
        b.adicionaAresta(arco);
        this.arestas.add(arco);
    }

    public void adicionaAresta(T dadoA, T dadoB, Double peso){
        Vertice<T> a = this.buscaVertice(dadoA);
        Vertice<T> b = this.buscaVertice(dadoB);
        Aresta<T> aresta = new Aresta<T>(peso,a,b);
        a.adicionaAresta(aresta);
        b.adicionaAresta(aresta);
        this.arestas.add(aresta);
    }

    public Vertice<T> buscaVertice(T dado){
        Vertice<T> vertice = null;
        for(int i=0; i < this.vertices.size(); i++){
            if(this.vertices.get(i).getDado().equals(dado)){
                vertice = this.vertices.get(i);
                break;
            }
        }
        return vertice;
    }

    public int getVerticePosition(T dado){ // A partir do dado do vertice busca qual indice ele ta na lista
        for(int i=0; i < this.vertices.size(); i++){
            if(this.vertices.get(i).getDado().equals(dado)){
                return i;
            }
        }
        return -1;
    }

    public void buscaLargura(T dado) { // O dado passado aqui é pra definir em qual vertice ira começar a busca
        int indexInicio = getVerticePosition(dado); // chama a rotina getVerticePosition pra pegar o i do dado que nos queremos começar
        if(indexInicio == -1){
            System.out.println("Vertice nao encontrado.");
            return;
        }
        ArrayList<Vertice<T>> marcados = new ArrayList<Vertice<T>>();
        ArrayList<Vertice<T>> fila = new ArrayList<Vertice<T>>();
        Vertice<T> atual = this.vertices.get(indexInicio);
        marcados.add(atual);
        System.out.println(atual.getDado());
        fila.add(atual);
        while (fila.size() > 0) {
            Vertice<T> visitado = fila.get(0);
            for (int i = 0; i < visitado.getArestas().size(); i++) {
                Vertice<T> proximo = visitado.getArestas().get(i).getB();
                if (!marcados.contains(proximo)) {
                    marcados.add(proximo);
                    System.out.println(" o " + proximo.getDado());
                    fila.add(proximo);
                }
            }
            fila.remove(0);
        }
    }
}
