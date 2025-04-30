/**
 * @nc app=nowcoder id=c7aa73afc41f4dfc925baebdd175c345 topic=298 question=40376 lang=MySQL
 * 2025-04-30 23:31:32
 * https://www.nowcoder.com/practice/c7aa73afc41f4dfc925baebdd175c345?tpId=298&tqId=40376
 * [SQL99] 返回购买 prod_id 为 BR01 的产品的所有顾客的电子邮件（二）
 */

/** @nc code=start */
SELECT cust_email
FROM Customers
JOIN Orders ON Customers.cust_id = Orders.cust_id
JOIN OrderItems ON Orders.order_num = OrderItems.order_num
WHERE prod_id = 'BR01';


/** @nc code=end */
