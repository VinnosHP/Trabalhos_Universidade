use trabalhom2;
insert into unidade(cidade) values
	("São José"),
    ("Florianópolis"),
    ("Palhoça"),
    ("Biguaçu");
insert into vendedor(nome, matricula) values
	("Arlindo Neves",123),
    ("Maria Silvia",321),
    ("Joarez Lima",456),
    ("Miranda Maria",654);
insert into produto(descricao, preco) values
	("Geleia",20.00),
	("Fruta",2.99),
    ("Pão",0.99),
    ("Carne",8.99),
    ("Água",7.99);
insert into venda(quantidade, dataa, unidade, produto, vendedor) values	
	(15000.00, "2023-01-23", 2, 4, 1),
    (20.00, "2020-08-08", 3, 2, 4),
    (15.00, "2021-01-08", 3, 2, 4),
    ( 7.00, "2022-05-03", 3, 3, 3),
    (11.00, "2023-04-20", 1, 1, 4),
	(10.00, "2023-04-02", 1, 1, 4),
    ( 2.00, "2023-02-07", 3, 1, 2),
    (13.00, "2023-03-07", 4, 3, 3);