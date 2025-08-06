# Write your MySQL query statement below
-- select l1.id from Logs l1 cross join  Logs l2 where l1.num = l2.num AND l1.id + 1 = l2.id;
select distinct l1.num as ConsecutiveNums 
from Logs l1
join Logs l2 
on l1.id + 1 = l2.id
AND l1.num = l2.num
join Logs l3
on l2.id  +1 = l3.id
ANd l2.num = l3.num;