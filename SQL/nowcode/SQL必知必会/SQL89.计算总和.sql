/**
 * @nc app=nowcoder id=d8a624021183454586da94d280cc8046 topic=298 question=40366 lang=MySQL
 * 2025-04-24 21:41:32
 * https://www.nowcoder.com/practice/d8a624021183454586da94d280cc8046?tpId=298&tqId=40366
 * [SQL89] 计算总和
 */

/** @nc code=start */
SELECT order_num, SUM(quantity * item_price) AS total_price
FROM OrderItems
GROUP BY order_num
HAVING SUM(quantity * item_price) >= 1000;


/** @nc code=end */
