# Write your MySQL query statement below
select project_id , round(avg(experience_years),2) as average_years from (select p.project_id , e.experience_years from Project p inner join Employee e on  e.employee_id = p.employee_id) as full group by project_id;
