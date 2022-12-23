clc
close
clear
//integração sem função, funcionando

X = [0 0.5 1 1.5 2 2.5 3]    //todos os Xs
Y = [5.021 6.146 6.630 6.945 7.178 7.364 7.519]             //todos os Ys
n = (size(X,2)-1)           //numero de passos
h = X(2) - X(1)
soma = 0

if(n > 1) then
    for i=2:n
        soma = soma + 2*(Y(i))
    end
    I = (h/2)*(Y(1)+ soma +Y(n+1))
else
    I = (h/2)*(Y(1)+Y(2))
end

disp("resultado:")
disp(I)
