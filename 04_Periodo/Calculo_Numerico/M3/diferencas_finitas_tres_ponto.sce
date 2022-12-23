clear
close
clc

//3 pontos : funcionando, falta resultado do ponto que é dado,
//mas acho que da para fazer na mão, exemplo 2 slide 15

function f=f(x)
    f= x*exp(x)
endfunction

X = [1.05 1.10 1.15 1.20 1.25 1.30]
Y = [-1.709847 -1.373823 -1.119214 -0.9160143 -0.7470223 -0.6015966]
h = 0.05

resultado = (1/(2*h))*(-3*f(X(3))+4*f(X(3)+h)-f(X(3)+2*h)) //diferença progressiva
disp("Resultado Progressiva")
disp(resultado)
resultado = (1/(2*h))*(f(X(3)+h)-f(X(3)-h))                  //diferença central
disp("Resultado Central")
disp(resultado)
resultado = (1/(2*h))*(f(X(4)+h)-f(X(4)-h))                  //diferença central
disp("Resultado Central 2")
disp(resultado)
resultado = (1/(2*h))*(f(X(4)-2*h)-4*f(X(4)-h)+3*f(X(4)))   //diferença regressiva
disp("Resultado Regressiva")
disp(resultado)
