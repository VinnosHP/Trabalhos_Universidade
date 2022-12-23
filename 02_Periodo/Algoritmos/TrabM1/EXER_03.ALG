Algoritmo "EXER_03"
VAR
   dia,mes:inteiro
INICIO
   escreval("Informe o dia do seu nacimento: ")
   leia(dia)
   escreval("Informe o més do seu nacimento: ")
   leia(mes)
   escolha(mes)
   caso 1
      se(dia <= 20)entao
         escreval ("signo: capricórnio.")
      senao
         escreval ("signo: aguário.")
      fimse
   caso 2
      se (dia <=19)entao
         escreval("signo: aguário.")
      senao
         escreval("signo: peixes")
      fimse
   caso 3
      se (dia <=20)entao
         escreval("signo: peixes.")
      senao
         escreval("signo: aries.")
      fimse
   caso 4
      se (dia <=20)entao
         escreval("signo: aries.")
      senao
         escreval("signo: touro.")
      fimse
   caso 5
      se (dia <=20)entao
         escreval("signo: touro.")
      senao
         escreval("signo: gemeos.")
      fimse
   caso 6
      se (dia <=21)entao
         escreval("signo: gemeos.")
      senao
         escreval("signo: cancer.")
      fimse
   caso 7
      se (dia <=22)entao
         escreval("signo: cancer.")
      senao
         escreval("signo: leao.")
      fimse
   caso 8
      se (dia <=22)entao
         escreval("signo: leao.")
      senao
         escreval("signo: virgem.")
      fimse
   caso 9
      se (dia <=22)entao
         escreval("signo: virgem.")
      senao
         escreval("signo: libra")
      fimse
   caso 10
      se (dia <=21)entao
         escreval("signo: libra.")
      senao
         escreval("signo: escorpiao.")
      fimse
   caso 11
      se (dia <=21)entao
         escreval("signo: escorpiao.")
      senao
         escreval("signo: sargitario.")
      fimse
   caso 12
      se (dia <=21)entao
         escreval("signo: sargitario.")
      senao
         escreval("signo: capricornio.")
      fimse
   outrocaso
      escreval("Dia ou mes invalido!")
   fimescolha
FIMALGORITMO