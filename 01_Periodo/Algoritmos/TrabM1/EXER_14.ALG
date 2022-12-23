Algoritmo "EXER_14"
Var
   I1, I2, I3: Inteiro
   PF: Real
Inicio
      PF <- 0
      Escreval("Escreva os tres codigos de produto:")
      Leia(I1, I2, I3)
      Se ((I1 > 0) e (I1 < 5)) Entao
         Escolha I1
            Caso 1
                 Escreval("Hamburguer: r$14,50")
                 PF <- PF + 14.5
            Caso 2
                 Escreval("Chessburguer: r$15,50")
                 PF <- PF + 15.5
            Caso 3
                 Escreval("Cachorro Quente: r$10,00")
                 PF <- PF + 10
            Caso 4
                 Escreval("Sanduiche Natural: r$13,50")
                 PF <- PF + 13.5
         Fimescolha
      Senao
           Escreval("Erro, codigo 1 invalido")
      Fimse
      Se ((I2 > 4) e (I2 < 7)) Entao
         Escolha I2
            Caso 5
                 Escreval("Refrigerante: r$5,00")
                 PF <- PF + 5
            Caso 6
                 Escreval("Suco de Laranja: r$6,00")
                 PF <- PF + 6
         Fimescolha
      Senao
           Escreval("Erro, codigo 2 invalido")
      Fimse
      Se ((I3 > 6) e (I3 < 10)) Entao
         Escolha I3
            Caso 7
                 Escreval("Milk Shake: r$10,5")
                 PF <- PF + 10.5
            Caso 8
                 Escreval("Sundae: r$13,00")
                 PF <- PF + 13
            Caso 9
                 Escreval("Casquinha: r$10,00")
                 PF <- PF + 10
         Fimescolha
      Senao
           Escreval("Erro, codigo 3 invalido")
      Fimse
      Escreval("Preço Final: r$", PF)
Fimalgoritmo