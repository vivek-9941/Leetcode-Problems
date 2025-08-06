# Write your MySQL query statement below
select p.product_name , q.total_unit as unit 
from Products p
inner join
(select  product_id,
        SUM(unit) AS total_unit from Orders where MONTH(order_date) = 2 AND YEAR(order_date) = 2020 group by product_id having sum(unit) >=100 ) q
on p.product_id =  q.product_id ; 


-- SELECT 
--     p.product_id,
--     q.total_unit
-- FROM Products p
-- INNER JOIN (
--     SELECT 
--         product_id,
--         SUM(unit) AS total_unit
--     FROM Orders
--     WHERE MONTH(order_date) = 2 
--       AND YEAR(order_date) = 2020
--     GROUP BY product_id
--     HAVING SUM(unit) >= 100
-- ) q
-- ON p.product_id = q.product_id;
