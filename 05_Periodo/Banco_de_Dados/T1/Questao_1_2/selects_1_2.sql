use questao_1_2;
select student.nome, student.roll_no, address.city, address.street
	from questao_1_2.student
	inner join questao_1_2.address
    on student.address = address.idAddress
    where address.city = 'Ulm';