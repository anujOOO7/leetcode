select d.name as department,
e.name as employee,
e.salary from employee as e 
inner join department as d 
on e.departmentId=d.id 
where (e.departmentId,e.salary) 
in(
  select departmentId ,max(salary) from employee
  group by departmentId
);