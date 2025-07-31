# Write your MySQL query statement below
select t1.id from Weather t1 INNER JOIN Weather t2 on DATEDIFF(t1.recordDate, t2.recordDate)  = 1 and t2.temperature  < t1.temperature ;