/**
 * @nc app=nowcoder id=ce313253a81c4947b20e801cd4da7894 topic=298 question=40371 lang=MySQL
 * 2025-04-25 17:04:20
 * https://www.nowcoder.com/practice/ce313253a81c4947b20e801cd4da7894?tpId=298&tqId=40371
 * [SQL94] 返回每个顾客不同订单的总金额
 */

/** @nc code=start */
SELECT cust_id, sum(item_price * quantity) AS total_ordered
FROM Orders, OrderItems
WHERE Orders.order_num = OrderItems.order_num
GROUP BY cust_id
ORDER BY total_ordered DESC;
/** @nc code=end */
