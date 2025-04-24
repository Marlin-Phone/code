/**
 * @nc app=nowcoder id=cf1f8d4a514d455aa0468718fb411f41 topic=298 question=40363 lang=MySQL
 * 2025-04-24 14:30:15
 * https://www.nowcoder.com/practice/cf1f8d4a514d455aa0468718fb411f41?tpId=298&tqId=40363
 * [SQL86] 返回每个订单号各有多少行数
 */

/** @nc code=start */
SELECT order_num, count(*) AS order_lines
FROM OrderItems
GROUP BY order_num
ORDER BY order_lines ASC;
/** @nc code=end */
