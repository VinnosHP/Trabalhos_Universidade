package GrafoDirigido;

import java.util.ArrayList;

public class GrafoDirigido<T>{
    private ArrayList<Vertice<T>> vertices;
    private ArrayList<Arco<T>> arcos;

    public GrafoDirigido(){
        this.vertices = new ArrayList<Vertice<T>>();
        this.arcos = new ArrayList<Arco<T>>();
    }

    public void adicionaVertice(T dado){
        Vertice<T> novoV = new Vertice<T>(dado);
        this.vertices.add(novoV);
    }

    public void adicionaArco(T dadoSaida, T dadoChegada){
        Vertice<T> saida = this.buscaVertice(dadoSaida);
        Vertice<T> chegada = this.buscaVertice(dadoChegada);
        Arco<T> arco = new Arco<T>(1.0,saida,chegada);
        saida.adicionaArcoSaida(arco);
        chegada.adicionaArcoEntrada(arco);
        this.arcos.add(arco);
    }

    public void adicionaArco(T dadoSaida, T dadoChegada, double peso){
        Vertice<T> saida = this.buscaVertice(dadoSaida);
        Vertice<T> chegada = this.buscaVertice(dadoChegada);
        Arco<T> arco = new Arco<T>(peso,saida,chegada);
        saida.adicionaArcoSaida(arco);
        chegada.adicionaArcoEntrada(arco);
        this.arcos.add(arco);
    }

    public Vertice<T> buscaVertice(T dado){ // Retorna o objeto Vertice que contem o "dado" dentro dele
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

    public void buscaLargura(T dado){ // O dado passado aqui é pra definir em qual vertice ira começar a busca
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
        while(fila.size() > 0){
            Vertice<T> visitado = fila.get(0);
            for(int i=0 ; i < visitado.getArcosSaida().size(); i++){
                Vertice<T> proximo = visitado.getArcosSaida().get(i).getFim();
                if(!marcados.contains(proximo)){
                    marcados.add(proximo);
                    System.out.println(proximo.getDado());
                    fila.add(proximo);
                }
            }
            fila.remove(0);
        }
    }
}
