-- # Write your MySQL query statement below

select Signups.user_id ,IFNULL(ROUND(e.confirmed / e.totalparticipate, 2),0) as  confirmation_rate from  Signups left join 
(select  full.user_id,
        full.totalparticipate,
        conf.confirmed  from (select user_id , count(action) as totalparticipate from Confirmations  group by user_id) as full INNER JOIN (select user_id , count(action) as confirmed from Confirmations where action = 'confirmed' group by user_id) as conf on full.user_id = conf.user_id) as e  on e.user_id = Signups.user_id;