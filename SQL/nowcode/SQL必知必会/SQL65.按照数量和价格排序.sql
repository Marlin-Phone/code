/**
 * @nc app=nowcoder id=bd05a6684e534bd1bf2d9ebbda475333 topic=298 question=40342 lang=MySQL
 * 2025-04-23 19:53:49
 * https://www.nowcoder.com/practice/bd05a6684e534bd1bf2d9ebbda475333?tpId=298&tqId=40342
 * [SQL65] 按照数量和价格排序
 */

/** @nc code=start */
SELECT *
FROM OrderItems
ORDER BY quantity DESC, item_price DESC;


/** @nc code=end */
