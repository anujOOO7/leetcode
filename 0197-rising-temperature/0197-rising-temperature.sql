# Write your MySQL query statement below
select weather.id as id from Weather inner join weather as w 
where DATEDIFF(weather.recordDate,w.recordDate)=1 
&& weather.temperature>w.temperature