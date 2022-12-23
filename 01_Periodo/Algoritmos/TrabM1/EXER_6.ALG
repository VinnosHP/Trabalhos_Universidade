Algoritmo "EXER_6"
Var
	opcao: Inteiro
	a, b, c, asort, bsort, csort: Real

Inicio
	Escreva("digite a opcaoo e os tres valores:")
	Leia(opcao, a, b, c)

	Se ((a > b) e (a > c)) Entao 
		asort <- a
		Se (b > c) Entao
			bsort <- b
			csort <- c
		Senao
			bsort <- c
			csort <- b
		Fimse
	Senao 
		Se ((b > a) e (b > c)) Entao 
			asort <- b
			Se (a > c) Entao
				bsort <- a
				csort <- c
			Senao
				bsort <- c
				csort <- a
			Fimse
		Senao 
			asort <- c
			Se (b > a) Entao
				bsort <- b
				csort <- a
			Senao
				bsort <- a
				csort <- b
			Fimse
		Fimse
	Fimse
	Escolha opcao
		Caso 1
			Escreval("em ordem crescente:", asort, bsort, csort)
		Caso 2
			Escreval("em ordem decrescente:", csort, bsort, asort)
		Caso 3
			Escreval("maior no meio:", bsort, asort, csort)
		Outrocaso
			Escreval("opcao incorreta")
	Fimescolha

Fimalgoritmo
