clc
close
clear
//integração com função, funcionando
function z=f(x)
    z= cos(x)/(1+x)       //tem que mudar quando a função for diferente
endfunction

a = 0       //ponto inicial
b = 1     //ponto final
n = 4      //iterações
h=(b-a)/n
x(1)=a
y(1)=f(a)
for i=2:n
    x(i)=x(i-1)+h
    y(i)=f(x(i))
end

I=(sum(y)*h)-(h/2*(y(1)+y(n)))
//I=(h/2)*(f(a)+f(b))
z=intg(a,b,f)
disp("I")
disp(I)
disp("Resultado")
disp(z)
