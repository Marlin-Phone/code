/**
 * @nc app=nowcoder id=a271dc25594a4db28f5b957aad07f9ee topic=298 question=40360 lang=MySQL
 * 2025-04-24 14:25:15
 * https://www.nowcoder.com/practice/a271dc25594a4db28f5b957aad07f9ee?tpId=298&tqId=40360
 * [SQL83] 确定已售出产品的总数
 */

/** @nc code=start */
SELECT SUM(quantity) AS items_ordered
FROM OrderItems;


/** @nc code=end */
