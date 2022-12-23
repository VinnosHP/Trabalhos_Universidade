clc
close
clear

a=0         //ponto inicial
b=0.3       //ponto final
h=0.1
y0=2

function f=f(x,y)
    f= -y+x+2
endfunction

x = [a: h: b]
y(1) = y0
n = length(x)

for i=2:n
    y(i)=y(i-1)+h*f(x(i-1),y(i-1))
end

disp("Respostas",y)
disp("N",n)
