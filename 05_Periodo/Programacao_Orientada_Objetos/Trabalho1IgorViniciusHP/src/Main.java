import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Objects;
import java.util.Scanner;
public class Main {
    public static void menu(){
        System.out.println("|----- MENU -----|");
        System.out.println("| 1 - Inclusão   |");
        System.out.println("| 2 - Venda      |");
        System.out.println("| 3 - Relatorio  |");
        System.out.println("|-1 - Sair       |");
        System.out.println("|----------------|");
        System.out.print(" Opção: ");
    }
    public static void inclusao(ArrayList<Produto> naoPerecivel) {
        Scanner input = new Scanner(System.in);
        Produto produto = new Produto();
        System.out.print("Nome: ");
        String nome = input.nextLine();
        produto.setNome(nome);
        System.out.print("Id: ");
        int id = input.nextInt();
        produto.setId(id);
        System.out.print("Quantidade no estoque: ");
        int qtde = input.nextInt();
        produto.setQuant(qtde);
        System.out.print("Preço de venda: ");
        double preco = input.nextDouble();
        produto.setPreco(preco);
        naoPerecivel.add(produto);
        System.out.println("Inclusao confirmada!");
    }
    public static void inclusaoP(ArrayList<Perecivel> pereciveis){
        Scanner input = new Scanner(System.in);
        Perecivel pere = new Perecivel();
        System.out.print("Nome: ");
        String nome = input.nextLine();
        pere.setNome(nome);
        System.out.print("Id: ");
        int id = input.nextInt();
        pere.setId(id);
        System.out.print("Quantidade no estoque: ");
        int qtde = input.nextInt();
        pere.setQuant(qtde);
        System.out.print("Preço de venda: ");
        double preco = input.nextDouble();
        pere.setPreco(preco);
        System.out.print("Data de vencimento(numero)");
        System.out.print("\nDia: ");
        int dia = input.nextInt();
        pere.setDia(dia);
        System.out.print("Mes: ");
        int mes = input.nextInt();
        pere.setMes(mes);
        System.out.print("Ano: ");
        int ano = input.nextInt();
        pere.setAno(ano);
        pereciveis.add(pere);
        System.out.println("inclusao confirmada!");
    }

    public static void vendaP(ArrayList<Perecivel> perecivel){
        Scanner input = new Scanner(System.in);
        System.out.print("Id: ");
        int id = input.nextInt();
        if (perecivel.size() == 0)
            System.out.println("Lista Vazia");
        else {
            for (int i = 0; i<perecivel.size(); i++){
                if (perecivel.get(i).getId() == id){
                    System.out.print("Quantidade Vendida: ");
                    int qtde = input.nextInt();
                    if (perecivel.get(i).getQuant() < qtde)
                        System.out.print("Venda cancelada por falta de estoque!");
                    else{
                        System.out.println("Quantidade: " + qtde);
                        System.out.println("Preço Unitario: R$" + perecivel.get(i).getPreco());
                        System.out.print("Dia: ");
                        int dia = input.nextInt();
                        System.out.print("Mes: ");
                        int mes = input.nextInt();
                        System.out.print("Ano: ");
                        int ano = input.nextInt();
                        if (perecivel.get(i).getAno() >= ano) {
                            if (perecivel.get(i).getMes() >= mes) {
                                if (perecivel.get(i).getDia() >= dia) {
                                    int diaDesc = perecivel.get(i).getDia() - 1;
                                    if (dia == diaDesc) {
                                        System.out.print("Desconto(ex: 10): ");
                                        int desconto = input.nextInt();
                                        double desc = perecivel.get(i).aplicaDesconto(desconto);
                                        double total = (perecivel.get(i).getPreco() - desc) * qtde;
                                        System.out.println("Preço Total:" + total);
                                    } else {
                                        double total = perecivel.get(i).getPreco() * qtde;
                                        System.out.println("Preço Total:" + total);
                                    }
                                }else{
                                    System.out.println("Produto Vencido!");
                                    return;
                                }
                            }else{
                                System.out.println("Produto Vencido!");
                                return;
                            }
                        }else{
                            System.out.println("Produto Vencido!");
                            return;
                        }
                        System.out.println("Confirmar venda s(sim)/n(nao)?");
                        char resp = input.next().charAt(0);
                        if (resp == 's'){
                            perecivel.get(i).setQuant(perecivel.get(i).getQuant() - qtde);
                            System.out.println("Venda Realizada!");
                        }else {
                            System.out.println("Venda Cancelada!");
                        }
                        return;
                    }
                }else
                    System.out.println("Produto Inexistente!");
            }
        }
    }
    public static void venda(ArrayList<Produto> naoPerecivel){
        Scanner input = new Scanner(System.in);
        System.out.print("Id: ");
        int id = input.nextInt();
        if (naoPerecivel.size() == 0)
            System.out.println("Lista Vazia");
        else {
            for (int i = 0; i<naoPerecivel.size(); i++){
                if (naoPerecivel.get(i).getId() == id){
                    System.out.print("Quantidade Vendida: ");
                    int qtde = input.nextInt();
                    if (naoPerecivel.get(i).getQuant() < qtde){
                        System.out.print("Venda cancelada por falta de estoque!");
                        return;
                    } else{
                        System.out.println("Quantidade: " + qtde);
                        System.out.println("Preço Unitario: R$" + naoPerecivel.get(i).getPreco());
                        double total = naoPerecivel.get(i).getPreco() * qtde;
                        System.out.println("Preço Total:" + total);
                        System.out.println("Confirmar venda s(sim)/n(nao)?");
                        char resp = input.next().charAt(0);
                        if (resp == 's'){
                            naoPerecivel.get(i).setQuant(naoPerecivel.get(i).getQuant() - qtde);
                            System.out.println("Venda Realizada!");
                        }else {
                            System.out.println("Venda Cancelada!");
                        }
                        return;
                    }
                }else
                    System.out.println("Produto Inexistente!");
            }
        }
    }

    public static void relatorioP (ArrayList<Perecivel> pereciveis){
        if (pereciveis.size() == 0)
            System.out.println("Não tem produtos pereciveis!");
        else {
            for (int i = 0; i < pereciveis.size(); i++) {
                pereciveis.get(i).display();
            }
        }
    }
    public static void relatorio (ArrayList<Produto> naoPerecivel){
        if (naoPerecivel.size() == 0)
            System.out.println("Não tem produtos pereciveis!");
        else {
            for (int i = 0; i < naoPerecivel.size(); i++) {
                naoPerecivel.get(i).display();
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        ArrayList<Perecivel> pereciveis = new ArrayList<>();
        ArrayList<Produto> naoPerecivel = new ArrayList<>();
        int op;
        do {
            menu();
            op = input.nextInt();
            switch (op) {
                case -1 -> System.out.println("Saindo...");
                case 1 -> {
                    System.out.print("O Produto eh perecivel (s/n)?");
                    char opc = input.next().charAt(0);
                    if (opc == 's')
                        inclusaoP(pereciveis);
                    else
                        inclusao(naoPerecivel);
                }
                case 2 -> {
                    System.out.print("O Produto eh perecivel (s/n)?");
                    char opc = input.next().charAt(0);
                    if (opc == 's')
                        vendaP(pereciveis);
                    else
                        venda(naoPerecivel);
                }
                case 3 -> {
                    System.out.println("\n");
                    relatorioP(pereciveis);
                    System.out.print("\n");
                    relatorio(naoPerecivel);
                }
                default -> System.out.println("Opção inválida!");
            }
            System.in.read();
        }while(op != -1);
    }
}