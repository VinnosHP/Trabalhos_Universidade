-- Agregações
use trabalhom2;

-- F
select p.descricao,
	count(v.quantidade) "Quantidade total de vendas",
    format(sum(v.quantidade * p.preco), 2) "Valor total de venda ($)"
	from venda v
    inner join produto p on v.produto = p.idProduto
    where p.idProduto = 1;

-- G
select ve.nome, count(v.quantidade) "Quantidade de vendas",
    format(sum(v.quantidade * p.preco), 2) "Valor total das vendas ($)",
    format(avg(v.quantidade * p.preco),2) "Valor médio por Venda ($)"
    from venda v
    inner join vendedor ve on v.vendedor = ve.idVendedor
    inner join produto p on v.produto = p.idProduto
    where ve.idVendedor = 4
    group by ve.nome order by v.vendedor;

-- H
select u.cidade, format(sum(v.quantidade * p.preco),2) "Valor total de vendas ($)"
	from venda v
    inner join unidade u on v.unidade = u.idUnidade
    inner join produto p on v.produto = p.idProduto
    where v.dataa > now() - interval 1 year
    group by u.idUnidade, p.preco
    having (p.preco * sum(v.quantidade)) > 100000;

-- I
select p.descricao, sum(v.quantidade) totalVenda
	from produto p
    left join venda v on v.produto = p.idProduto
    where v.dataa > now() - interval 3 month
    and v.dataa < now()
    group by p.idProduto
	having totalVenda < 20 union 
		select p.descricao, 0 totalVenda
		from produto p
		left join venda v on v.produto = p.idProduto
        where v.idVenda is null;

-- J
select ve.nome, ve.matricula, format(sum(p.preco * v.quantidade), 2) "Valor total de vendas"
	from vendedor ve
	left join venda v on v.vendedor = ve.idVendedor
	left join produto p on p.idProduto = v.produto
    where v.dataa > now() - interval 1 year
	group by ve.idVendedor
	having sum(p.preco * v.quantidade) > 
    (select avg(totalVendas)
		from (select sum(p.preco * v.quantidade) totalVendas
				from venda v
				left join produto p on p.idProduto = v.produto
				where v.dataa > now() - interval 1 year 
				and v.dataa < now()
				group by v.vendedor
            ) subquery
	);
 