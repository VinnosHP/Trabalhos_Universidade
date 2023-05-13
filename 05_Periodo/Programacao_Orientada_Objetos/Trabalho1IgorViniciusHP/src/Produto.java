public class Produto {
    private String nome;
    private int id;
    private int quant;
    private double preco;

    public Produto () {
        nome ="";
        id = 0;
        quant = 0;
        preco = 0.00;
    }

    public Produto (String nome, int id, int quant, double preco) {
        this.nome =nome;
        this.id = id;
        this.quant = quant;
        this.preco = preco;
    }

    public void setNome(String nome) { this.nome = nome; }
    public void setId(int id) { this.id = id; }
    public void setQuant(int quant) { this.quant = quant; }
    public void setPreco(double preco) { this.preco = preco; }

    public String getNome() { return nome; }
    public int getId() { return id; }
    public int getQuant() { return quant; }
    public double getPreco() { return preco; }

    public void display(){
        System.out.printf("%s: %s%n%s: %s%n%s: %s%n%s: %s%n",
                "Nome", getNome(), "Id", getId(),
                "Quantidade em estoque", getQuant(), "Preço", getPreco());
    }
}
