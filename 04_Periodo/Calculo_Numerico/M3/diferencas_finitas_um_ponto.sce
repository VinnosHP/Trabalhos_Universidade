clear
close
clc

function f=f(x)
    f=3*x*exp(x)-cos(x)         //pode ter questões que não dão a função
endfunction

h = 0.01
xk = 1.3

//2 ponto : funcionando, desconsiderar a central se pedir 2 pontos
resultado = (f(xk + h)-f(xk))/h  //diferença progressiva
disp("Resultado Progressiva")
disp(resultado)
resultado = (1/(2*h))*(f(xk+h)-f(xk-h))  //diferença central
disp("Resultado Central")
disp(resultado)
resultado = (f(xk)-f(xk - h))/h  //diferença regressiva
disp("Resultado Regressiva")
disp(resultado)

x=0
x = numderivative(f, xk)
disp("Derivada analitica")
disp(x)
