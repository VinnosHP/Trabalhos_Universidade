Algoritmo "EXER_10"
Var
   nome: caractere
   hx, ht, fal: real
   grat: inteiro
Inicio
   Escreval("Nome do funcionário:")
   Leia(nome)
   Escreval("Informe o numero de horas extras:")
   Leia(hx)
   Escreval("Informe o numero de faltas:")
   Leia(fal)

   ht <- hx - 2 / 3 * fal

   Se (ht <= 10) Entao
      grat <- 200
   Senao
      Se (ht <= 20) Entao
         grat <- 400
      Senao
         Se (ht <= 30) Entao
            grat <- 600
         Senao
            Se (ht <= 40) Entao
               grat <- 800
            Senao
               grat <- 1000
            Fimse
         Fimse
      Fimse
   Fimse
   
   Escreval("Funcionário: ",nome)
   Escreval("Bônus de: R$",grat)
Fimalgoritmo
