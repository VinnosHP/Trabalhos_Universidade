clc
close
clear

a=0         //ponto inicial
b=0.6       //ponto final
h=0.2
y0=1

function f=f(x,y)
    f= x^2+y
endfunction

x = [a: h: b]
y(1) = y0
n = length(x)

for i=2:n
    y(i)=y(i-1)+(h/2)*(f(x(i-1),y(i-1))+f(x(i-1)+h,y(i-1)+h*f(x(i-1),y(i-1))))
end

disp("Respostas",y)
disp("N",n)
