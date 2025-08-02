# Write your MySQL query statement below
select activity_date  as day, count(distinct user_id) as active_users
 from Activity 
 where activity_date between date('2019-06-28') and date('2019-07-27')
  group by activity_date ;


-- SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
-- FROM Activity
-- WHERE activity_date BETWEEN DATE('2019-06-28') AND DATE('2019-07-27')
-- GROUP BY activity_date;
