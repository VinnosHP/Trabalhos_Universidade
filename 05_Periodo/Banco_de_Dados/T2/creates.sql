create database trabalhoM2;
use trabalhoM2;
create table Unidade(
	idUnidade int auto_increment primary key,
	cidade varchar(40)
);

create table Produto(
	idProduto int auto_increment primary key,
    descricao varchar(50),
    preco float
);

create table Vendedor(
	idVendedor int auto_increment primary key,
    nome varchar(60),
    matricula int
);

create table Venda(
	idVenda int auto_increment primary key,
    quantidade float,
    dataa date,
    unidade int,
    foreign key (unidade) references Unidade(idUnidade),
    produto int,
    foreign key (produto) references Produto(idProduto),
    vendedor int,
    foreign key (vendedor) references Vendedor(idVendedor)
);