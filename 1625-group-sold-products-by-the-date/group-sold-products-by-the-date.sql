# Write your MySQL query statement below
-- select s.sell_date ,
-- s.count(*)  as num_sold ,
-- (select product from Activities where sell_date =s.sell_date  ) 
-- product from Activities
--  group by sell_date s;

--  select from Activities group by sell_date;
SELECT sell_date,count(distinct product) as num_sold ,  GROUP_CONCAT(distinct(product) ORDER BY product) AS products
FROM Activities
GROUP BY sell_date
order by sell_date;
