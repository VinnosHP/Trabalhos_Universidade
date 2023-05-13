-- Junções
use trabalhom2;

-- A
select p.descricao, p.preco, v.quantidade, u.cidade, v.dataa  
	from venda v
    inner join produto p on v.produto = p.idProduto
    inner join unidade u on v.unidade = u.idUnidade
    where v.produto = 2;

-- B
select ve.nome, ve.matricula, u.cidade, p.descricao, p.preco, v.quantidade, v.dataa
	from vendedor ve
    inner join venda v on ve.idVendedor = v.vendedor
    inner join unidade u on u.idUnidade = v.unidade
    inner join produto p on v.produto = p.idProduto
    where ve.idVendedor = 3;
    
-- C
select p.descricao, p.preco, v.quantidade, u.cidade, v.dataa
	from venda v 
    inner join unidade u on v.unidade = u.idUnidade
    inner join produto p on v.produto = p.idProduto
    where u.idUnidade = 3
    and v.dataa > now() - interval 2 year
    and v.dataa < now();
    
-- D
select p.descricao, p.idProduto
	from produto p
    where p.idProduto not in(
		select v.produto 
        from venda v 
        where v.dataa > now() - interval 1 month 
        and v.dataa < now()
	)
    group by p.idProduto;

-- E
select ve.nome, ve.matricula
	from vendedor ve
    where ve.idVendedor not in(
		select v.vendedor 
        from venda v 
        where v.dataa > now() - interval 20 day
        and v.dataa < now()
	);
    