# Write your MySQL query statement below

SELECT firstName , lastName , city , state 
FROM person p
 left join Address a 
ON p.personId = a.personId;
