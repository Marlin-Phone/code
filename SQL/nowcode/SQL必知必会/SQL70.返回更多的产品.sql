/**
 * @nc app=nowcoder id=dc91b7d2de3c4603a55995e83210f605 topic=298 question=40347 lang=MySQL
 * 2025-04-23 20:20:35
 * https://www.nowcoder.com/practice/dc91b7d2de3c4603a55995e83210f605?tpId=298&tqId=40347
 * [SQL70] 返回更多的产品
 */

/** @nc code=start */
SELECT DISTINCT order_num
FROM OrderItems
WHERE quantity >= 100;


/** @nc code=end */
