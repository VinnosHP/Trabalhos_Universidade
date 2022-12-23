Algoritmo "EXER_02"
VAR
   resul,x:real
INICIO
   escreva("Informe o X:")
   leia(x)
   se(x<=-2)entao
      resul<- 1 + x
   fimse
   se((x>-2)e(x<2))entao
      resul<- 2 - x
   fimse
   se(x>=2)entao
      resul<- 2 * x - 1
   fimse
   escreval("X = ",resul)
FIMALGORITMO