SELECT employee_id , name ,(count(*)) as  reports_count   ,round(avg(age)) as average_age  from(
SELECT e.employee_id, e.name ,e2.age as age
FROM Employees e 
INNER JOIN Employees e2 ON e.employee_id = e2.reports_to) as output group by employee_id order by employee_id;
