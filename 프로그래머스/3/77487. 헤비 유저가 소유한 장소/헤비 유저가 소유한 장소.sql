select ID, NAME, HOST_ID
from places
where host_id in
(SELECT HOST_ID
from places
group by HOST_ID
having count(*)>=2)
order by 1