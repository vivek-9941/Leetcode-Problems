SELECT 
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(*) AS trans_count,
    SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count,
    SUM(amount) as trans_total_amount ,
    SUM(case when state = 'approved' THEN amount else 0 END) AS approved_total_amount 
FROM 
    Transactions
GROUP BY 
    DATE_FORMAT(trans_date, '%Y-%m'), country;
