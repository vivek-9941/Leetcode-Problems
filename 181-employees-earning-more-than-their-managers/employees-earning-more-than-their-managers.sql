# Write your MySQL query statement below
SELECT e1.name AS Employee  FROM Employee e1 inner join Employee e2 on e1.managerId = e2.id where e2.salary < e1.salary;