/**
 * @nc app=nowcoder id=b5766f970ae64ac7944f37f5b47107aa topic=298 question=40377 lang=MySQL
 * 2025-04-30 23:37:53
 * https://www.nowcoder.com/practice/b5766f970ae64ac7944f37f5b47107aa?tpId=298&tqId=40377
 * [SQL100] 确定最佳顾客的另一种方式（二）
 */

/** @nc code=start */
SELECT cust_name, SUM(item_price * quantity) AS total_price
FROM OrderItems
JOIN Orders ON OrderItems.order_num = Orders.order_num
JOIN Customers ON Orders.cust_id = Customers.cust.id
WHERE SUM(item_price * quantity) >= 1000
-- GROUP BY cust_name
ORDER BY total_price ASC;



/** @nc code=end */
