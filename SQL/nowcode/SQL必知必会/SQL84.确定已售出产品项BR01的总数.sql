/**
 * @nc app=nowcoder id=a225d8a7bc4f496283fe8e21293e841c topic=298 question=40361 lang=MySQL
 * 2025-04-24 14:26:47
 * https://www.nowcoder.com/practice/a225d8a7bc4f496283fe8e21293e841c?tpId=298&tqId=40361
 * [SQL84] 确定已售出产品项 BR01 的总数
 */

/** @nc code=start */
SELECT SUM(quantity) AS items_ordered
FROM OrderItems
WHERE prod_id = 'BR01';


/** @nc code=end */
