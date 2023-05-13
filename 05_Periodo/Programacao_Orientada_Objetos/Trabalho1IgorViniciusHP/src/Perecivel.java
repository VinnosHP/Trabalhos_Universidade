public class Perecivel extends Produto{
    private int dia;
    private int mes;
    private int ano;

    public Perecivel() {
        this.dia = 0;
        this.mes = 0;
        this.ano = 0;
    }
    public Perecivel(String nome, int id, int quant, double preco, int dia, int mes, int ano) {
        super(nome, id, quant, preco);
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public void setDia(int dia) { this.dia = dia; }
    public void setMes(int mes) { this.mes = mes; }
    public void setAno(int ano) { this.ano = ano; }

    public int getDia() { return dia; }
    public int getMes() { return mes; }
    public int getAno() { return ano; }

    public boolean estaVencido (int dia, int mes, int ano){
        return this.dia < dia && this.mes < mes && this.ano < ano;
    }

    public double aplicaDesconto (double desconto){
        double desc;
        desc = getPreco() * (desconto / 100);
        return desc;
    }

    public void display(){
        super.display();
        System.out.printf("%s: %s/%s/%s%n", "Data de Vencimento",
                getDia(), getMes(), getAno());
    }
}
