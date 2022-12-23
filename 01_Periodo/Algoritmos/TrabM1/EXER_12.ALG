Algoritmo "EXER_12"

Var
mat: Inteiro
VP1A, VP1B, VP2, ME, MA: Real
CN: caractere

Inicio
   Escreval("Escreva a matricula:")
   Leia(mat)

   Escreval("Escreva as tres verificacoes parciais:")
   Leia(VP1A, VP1B, VP2)

   Escreval("Escreva a media dos exercicios:")
   Leia(ME)
   
   MA <- (VP1A + VP1B * 2 + VP2 * 3 + ME) / 7
   
   Se (MA >= 9.0) Entao
      CN <- "A"
   Senao
        Se (MA >= 7.5) Entao
           CN <- "B"
        Senao
             Se (MA >= 6.0) Entao
                CN <- "C"
             Senao
                  Se (MA >= 4.0) Entao
                     CN <- "D"
                  Senao
                       CN <- "E"
                  Fimse
             Fimse
        Fimse
   Fimse
   
   Escreval("Matricula: ", MA)
   Escreval("Notas: ", VP1A, VP1B, VP2)
   Escreval("Media dos exercicios: ", ME)
   Escreval("Conceito: ", CN)

   Escolha CN
      Caso "A"
      Caso "B"
      Caso "C"
           Escreval("Situação: Aprovado")
      Caso "D"
      Caso "E"
           Escreval("Situação: Reprovado")
   Fimescolha

Fimalgoritmo
