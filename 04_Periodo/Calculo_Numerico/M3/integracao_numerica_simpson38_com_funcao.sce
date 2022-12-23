clc
close
clear
//integração ocm função simpson 1/3, funcionando

function f=f(x)
    f= log(x+2)-1      //mudar se tiver função
endfunction

a = 2   //ponto inicial
b = 3.2   //ponto final
n = 6   //numero de intervalo, pode ou n ser informado
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
        if(modulo(i-1,3) == 0) then
            soma = soma + 2*(Y(i))
        else
            soma = soma + 3*(Y(i))
        end
    end
    I = ((3*h)/8)*(f(a)+ soma +f(b))
else
    I = ((3*h)/8)*(f(a)+f(b))
end

disp("resultado:")
disp(I)
