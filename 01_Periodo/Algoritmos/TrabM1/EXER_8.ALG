Algoritmo "EXER_8"
Var
   a, b, c, del, x1, x2: real
Inicio
   Escreva("Informe a, b e c respectivamente:")
   Leia(a, b, c)

   del <- b ^ 2 - 4 * a * c

   Se (del < 0) Entao
      Escreval("Delta = ", del)
      Escreva("Não existem raízes reais!")
   Senao
      Se (del = 0) Entao
         x1 <- -b / (2 * a)
         Escreval("Delta = ", del)
         Escreval("x' = x'' = ", x1)
      Senao
         x1 <- (-b - Raizq(del)) / (2 * a)
         x2 <- (-b + Raizq(del)) / (2 * a)
         Escreval("x' = ", x1)
         Escreval("x'' = ", x2)
      Fimse
   Fimse
Fimalgoritmo
