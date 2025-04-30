/**
 * @nc app=nowcoder id=4dda66e385c443d8a11570a70807d250 topic=298 question=40374 lang=MySQL
 * 2025-04-30 00:32:49
 * https://www.nowcoder.com/practice/4dda66e385c443d8a11570a70807d250?tpId=298&tqId=40374
 * [SQL97] 返回顾客名称和相关订单号以及每个订单的总价
 */

/** @nc code=start */
SELECT cust_name, Customers.cust_id, (
    SELECT quantity * item_price AS total_price
    FROM OrderItems
)
FROM Customers, Orders, OrderItems
WHERE Customers.cust_id = Orders.cust_id AND OrderItems.order_num = Orders.order_num;

/** @nc code=end */
