/**
 * @nc app=nowcoder id=999aa31a9a504c60baa088d90d82e64d topic=298 question=40375 lang=MySQL
 * 2025-04-30 23:21:38
 * https://www.nowcoder.com/practice/999aa31a9a504c60baa088d90d82e64d?tpId=298&tqId=40375
 * [SQL98] 确定哪些订单购买了 prod_id 为 BR01 的产品（二）
 */

/** @nc code=start */
SELECT cust_id, order_date
FROM Orders
JOIN OrderItems ON OrderItems.order_num = Orders.order_num
WHERE prod_id = 'BR01'
ORDER BY order_date ASC;


/** @nc code=end */
