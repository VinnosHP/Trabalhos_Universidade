Algoritmo "EXER_01"
VAR
   idade,tempoS:inteiro
   sexo:caractere
INICIO
   escreva("Informe a idade da pessoa:")
   leia(idade)
   escreva("Informe o sexo(M/F) da pessoa:")
   leia(sexo)
   sexo<-maiusc(sexo)
   escreva("Informe o tempo de servico da pessoa:")
   leia(tempoS)
   escolha(sexo)
   caso "M","m"
      se((idade>=65)e(tempoS>=30))entao
         escreval("Parabens, voce pode se aposentar.")
      senao
         escreval("Nao pode se aposentar ainda.")
      fimse
   caso "F","f"
      se((idade>=60)e(tempoS>=25))entao
         escreval("Parabens, voce pode se aposentar.")
      senao
         escreval("Nao pode se aposentar ainda.")
      fimse
   fimescolha
FIMALGORITMO