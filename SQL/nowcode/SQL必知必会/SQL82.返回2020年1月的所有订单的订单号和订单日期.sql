/**
 * @nc app=nowcoder id=c7734db33854477aa94ae238a3390435 topic=298 question=40359 lang=MySQL
 * 2025-04-24 14:21:05
 * https://www.nowcoder.com/practice/c7734db33854477aa94ae238a3390435?tpId=298&tqId=40359
 * [SQL82] 返回 2020 年 1 月的所有订单的订单号和订单日期
 */

/** @nc code=start */
SELECT order_num, order_date
FROM Orders
WHERE order_date LIKE '2020-01%'
ORDER BY order_date ASC;


/** @nc code=end */
