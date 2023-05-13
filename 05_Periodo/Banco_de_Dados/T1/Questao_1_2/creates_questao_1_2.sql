create database questao_1_2;
use questao_1_2;
create table address (
    idAddress int auto_increment primary key, 
    country varchar(40),
    state varchar (40),
    city varchar (40),
    street varchar (40)
);

create table phone(
    idPhone int auto_increment primary key,
    phone_number varchar(14)
);

create table student (
    roll_no int primary key auto_increment,
    nome varchar(20),
    dob varchar (10),
    age varchar(3) generated always as (year('2023-04-06') - year(dob)) stored,
    address int,
    foreign key (address) references address(idAddress),
    phone_no int,
    foreign key (phone_no) references phone(idPhone)
);