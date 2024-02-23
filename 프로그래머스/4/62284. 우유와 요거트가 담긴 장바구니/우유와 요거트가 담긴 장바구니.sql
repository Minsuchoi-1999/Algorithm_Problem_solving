select distinct cart_id
from cart_products
where cart_id in (
SELECT distinct cart_id
from cart_products
where name = 'Yogurt'
)
and
cart_id in
(
SELECT distinct cart_id
from cart_products
where name = 'Milk'
)
order by 1