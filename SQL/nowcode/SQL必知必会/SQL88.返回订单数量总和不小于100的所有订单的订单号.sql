/**
 * @nc app=nowcoder id=ff77e82b59544a15987324e19488aafd topic=298 question=40365 lang=MySQL
 * 2025-04-24 21:29:54
 * https://www.nowcoder.com/practice/ff77e82b59544a15987324e19488aafd?tpId=298&tqId=40365
 * [SQL88] 返回订单数量总和不小于100的所有订单的订单号
 */

/** @nc code=start */
SELECT order_num
FROM OrderItems
GROUP BY order_num
HAVING SUM(quantity) >= 100
ORDER BY order_num ASC;


/** @nc code=end */
