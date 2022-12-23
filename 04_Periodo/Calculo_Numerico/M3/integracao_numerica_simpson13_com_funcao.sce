clc
close
clear
//integração com função simpson 1/3, funcionando

function f=f(x)
    f= exp(2*x)      //mudar se tiver função
endfunction

a = 1   //ponto inicial
b = 2   //ponto final
n = 4   //numero de intervalo, pode ou n ser informado
X = []
Y = []
h = (b-a)/n // passo
soma = 0

if(n > 1) then
    i= 1
    for k=a:h:b
        X(i) = k
        Y(i) = f(k)
        i = i + 1
    end
    for i=2:n
        if(modulo(i,2) == 0) then
            soma = soma + 4*(Y(i))
        else
            soma = soma + 2*(Y(i))
        end
    end
    I = (h/3)*(f(a)+ soma +f(b))
else
    I = (h/3)*(f(a)+f(b))
end

disp("resultado:")
disp(I)
