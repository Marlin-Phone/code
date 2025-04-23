/**
 * @nc app=nowcoder id=fa4eb4880d124a4ead7a9b025fe75b70 topic=298 question=40341 lang=MySQL
 * 2025-04-23 19:51:55
 * https://www.nowcoder.com/practice/fa4eb4880d124a4ead7a9b025fe75b70?tpId=298&tqId=40341
 * [SQL64] 对顾客ID和日期排序
 */

/** @nc code=start */
SELECT cust_id, order_num
FROM Orders
ORDER BY cust_id ASC, order_date DESC;


/** @nc code=end */
