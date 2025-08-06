# Write your MySQL query statement below
select person_name  from 
(select person_id ,turn as Turn ,person_name, sum(weight) over( order by turn )  as Total from Queue ) as t where Total <=1000 order by Turn desc limit 1 ;