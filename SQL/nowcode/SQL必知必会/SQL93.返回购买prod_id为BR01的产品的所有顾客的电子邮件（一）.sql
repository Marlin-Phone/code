/**
 * @nc app=nowcoder id=962b16554fbf4b99a87f4d68020c5bfb topic=298 question=40370 lang=MySQL
 * 2025-04-25 16:58:04
 * https://www.nowcoder.com/practice/962b16554fbf4b99a87f4d68020c5bfb?tpId=298&tqId=40370
 * [SQL93] 返回购买 prod_id 为 BR01 的产品的所有顾客的电子邮件（一）
 */

/** @nc code=start */
SELECT cust_email
FROM Customers, OrderItems, Orders
WHERE prod_id = 'BR01' AND OrderItems.order_num = Orders.order_num AND Orders.cust_id = Customers.cust_id;


/** @nc code=end */
