/**
 * @nc app=nowcoder id=b692b0174c0444fa9452aee2d082fbbb topic=298 question=40369 lang=MySQL
 * 2025-04-25 15:15:30
 * https://www.nowcoder.com/practice/b692b0174c0444fa9452aee2d082fbbb?tpId=298&tqId=40369
 * [SQL92] 确定哪些订单购买了 prod_id 为 BR01 的产品（一）
 */

/** @nc code=start */
SELECT cust_id, order_date
FROM OrderItems, Orders
WHERE OrderItems.order_num = Orders.order_num AND OrderItems.prod_id = 'BR01'
ORDER BY order_date;


/** @nc code=end */
