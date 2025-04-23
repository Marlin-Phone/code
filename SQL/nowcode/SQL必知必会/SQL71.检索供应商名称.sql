/**
 * @nc app=nowcoder id=c4d520ed6a264ad3900eff95e4195d59 topic=298 question=40348 lang=MySQL
 * 2025-04-23 20:21:47
 * https://www.nowcoder.com/practice/c4d520ed6a264ad3900eff95e4195d59?tpId=298&tqId=40348
 * [SQL71] 检索供应商名称
 */

/** @nc code=start */
SELECT vend_name
FROM Vendors
WHERE vend_country LIKE 'USA' AND vend_state = 'CA';


/** @nc code=end */
