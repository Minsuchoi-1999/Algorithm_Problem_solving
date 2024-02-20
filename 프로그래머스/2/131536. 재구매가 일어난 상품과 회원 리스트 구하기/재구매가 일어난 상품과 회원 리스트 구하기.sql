SELECT 
    USER_ID,
    PRODUCT_ID
FROM 
    ONLINE_SALE
WHERE 
    (USER_ID, PRODUCT_ID, SALES_DATE) IN 
    (
        SELECT 
            USER_ID,
            PRODUCT_ID,
            MIN(SALES_DATE) AS first_purchase_date
        FROM 
            ONLINE_SALE
        GROUP BY 
            USER_ID,
            PRODUCT_ID
        HAVING 
            COUNT(*) > 1
    )
ORDER BY 
    USER_ID ASC, PRODUCT_ID DESC;