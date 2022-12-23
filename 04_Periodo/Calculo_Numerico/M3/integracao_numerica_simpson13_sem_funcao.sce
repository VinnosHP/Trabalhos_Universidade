clc
close
clear
//integração simpson 1/3 sem função, funcionando

X = [1 1.1 1.2 1.3 1.4 1.5 1.6]   //todos Xs
Y = [0.099 0.131 0.163 0.194 0.224  0.253 0.281]   //todos Ys
n = (size(X,2)-1)           //numero de passos
h = X(2) - X(1)
soma = 0

if(n > 1) then
    for i=2:n
        if(modulo(i,2) == 0) then
            soma = soma + 4*(Y(i))
        else
            soma = soma + 2*(Y(i))
        end
    end
    I = (h/3)*(Y(1)+ soma +Y(n+1))
else
    I = (h/3)*(Y(1)+Y(2))
end

disp("resultado:")
disp(I)
