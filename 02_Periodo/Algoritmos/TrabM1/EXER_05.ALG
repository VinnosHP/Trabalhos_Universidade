Algoritmo "EXER_05"
Var
   cod1,cod2,cod3:inteiro
   preco:real
Inicio
   preco<- 0
   escreval("===============================")
   escreva("Informe o codigo do alimento:")
   leia(cod1)
   escreval("-------------------------------")
   se((cod1>0)e(cod1<5))entao
      escolha cod1
      caso 1
         escreval("Hamburguer: R$14,50")
         preco<- preco + 14.5
      caso 2
         escreval("Chessburguer: R$15,50")
         preco<- preco + 15.5
      caso 3
         escreval("Cachorro Quente: R$10,00")
         preco<- preco + 10
      caso 4
         escreval("Sanduiche Natural: R$13,50")
         preco<- preco + 13.5
      fimescolha
   senao
      escreval("Erro, codigo de alimento invalido!")
   fimse
   escreval("===============================")
   escreva("Informe o codigo da bebida:")
   leia(cod2)
   escreval("-------------------------------")
   se((cod2>4)e(cod2<7))entao
      escolha cod2
      caso 5
         escreval("Refrigerante: R$5,00")
         preco<- preco + 5
      caso 6
         escreval("Suco de Laranja: R$6,00")
         preco<- preco + 6
      fimescolha
   senao
      escreval("Erro, codigo de bebida invalido!")
   fimse
   escreval("===============================")
   escreva("Informe o codigo da sobremesa:")
   leia(cod3)
   escreval("-------------------------------")
   se((cod3>6)e(cod3<10))entao
      escolha cod3
      caso 7
         escreval("Milk Shake: R$10,5")
         preco<- preco + 10.5
      caso 8
         escreval("Sundae: R$13,00")
         preco<- preco + 13
      caso 9
         escreval("Casquinha: R$10,00")
         preco<- preco + 10
      fimescolha
   senao
      escreval("Erro, codigo de sobremesa invalido!")
   fimse
   escreval("===============================")
   escreval("Total a Pagar: R$",preco:2:2)
   escreval("===============================")
Fimalgoritmo