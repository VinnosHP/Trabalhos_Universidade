Algoritmo "EXER_04"
VAR
   matri:inteiro
   p1A,p1B,p2,mediaE,mediaA:real
   conc:caractere
INICIO
   escreval("Informe a matricula:")
   leia(matri)
   escreval("Informe as tres notas das verificacoes parciais:")
   leia(p1A, p1B, p2)
   escreval("Informe a media dos exercicios:")
   leia(mediaE)
   mediaA <- (p1A + p1B * 2 + p2 * 3 + mediaE)/7
   se(mediaA >= 9.0)entao
      conc <- "A"
   senao
      se(mediaA >= 7.5)entao
         conc <- "B"
      senao
         se(mediaA >= 6.0)entao
            conc <- "C"
         senao
            se(mediaA >= 4.0)entao
               conc <- "D"
            senao
               conc <- "E"
            fimse
         fimse
      fimse
   fimse
   escreval("Matricula: ",matri)
   escreval("Notas: ",p1A,p1B,p2)
   escreval("Media dos exercicios: ",mediaE)
   escreval("Conceito: ",conc)
   escolha conc
   caso "A"
      escreval("Situacao: Aprovado")
   caso "B"
      escreval("Situacao: Aprovado")
   caso "C"
      escreval("Situacao: Aprovado")
   caso "D"
      escreval("Situacao: Reprovado")
   caso "E"
      escreval("Situacao: Reprovado")
   fimescolha
FIMALGORITMO