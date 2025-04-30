/**
 * @nc app=nowcoder id=7e7bc361db6a4cb6aa35eefccfe75364 topic=298 question=40373 lang=MySQL
 * 2025-04-28 18:26:47
 * https://www.nowcoder.com/practice/7e7bc361db6a4cb6aa35eefccfe75364?tpId=298&tqId=40373
 * [SQL96] 返回顾客名称和相关订单号
 */

/** @nc code=start */
-- SELECT cust_name, order_num
-- FROM Customers, Orders
-- WHERE Customers.cust_id = Orders.cust_id
-- ORDER BY cust_name ASC, order_num DESC;

SELECT cust_name, order_num
FROM Customers
INNER JOIN Orders ON Customers.cust_id = Orders.cust_id
ORDER BY cust_name ASC, order_num ASC;


/** @nc code=end */
