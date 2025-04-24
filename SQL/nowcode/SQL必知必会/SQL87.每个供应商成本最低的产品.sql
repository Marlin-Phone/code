/**
 * @nc app=nowcoder id=f0679d06b50049499691e12a435de8d8 topic=298 question=40364 lang=MySQL
 * 2025-04-24 14:46:37
 * https://www.nowcoder.com/practice/f0679d06b50049499691e12a435de8d8?tpId=298&tqId=40364
 * [SQL87] 每个供应商成本最低的产品
 */

/** @nc code=start */
SELECT vend_id, MIN(prod_price) AS cheapest_item
FROM Products
GROUP BY vend_id
ORDER BY cheapest_item ASC;


/** @nc code=end */
