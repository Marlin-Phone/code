/**
 * @nc app=nowcoder id=3870c9bca7a4406f899af3e903b8bf51 topic=298 question=40367 lang=MySQL
 * 2025-04-24 21:54:10
 * https://www.nowcoder.com/practice/3870c9bca7a4406f899af3e903b8bf51?tpId=298&tqId=40367
 * [SQL90] 纠错3
 */

/** @nc code=start */
SELECT order_num, COUNT(*) AS items
FROM OrderItems
GROUP BY order_num
HAVING count(*) >= 3
ORDER BY order_num;


/** @nc code=end */
