/**
 * @nc app=nowcoder id=674d99a46a96494d8267ae4d162ed459 topic=298 question=40349 lang=MySQL
 * 2025-04-23 20:24:19
 * https://www.nowcoder.com/practice/674d99a46a96494d8267ae4d162ed459?tpId=298&tqId=40349
 * [SQL72] 检索并列出已订购产品的清单
 */

/** @nc code=start */
SELECT order_num, prod_id, quantity
FROM OrderItems
WHERE prod_id in ('BR01', 'BR02', 'BR03') AND quantity >= 100;

/** @nc code=end */
