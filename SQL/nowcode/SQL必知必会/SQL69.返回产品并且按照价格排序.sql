/**
 * @nc app=nowcoder id=560c94bf434e4e77911982e2d7ca0abb topic=298 question=40346 lang=MySQL
 * 2025-04-23 20:18:55
 * https://www.nowcoder.com/practice/560c94bf434e4e77911982e2d7ca0abb?tpId=298&tqId=40346
 * [SQL69] 返回产品并且按照价格排序
 */

/** @nc code=start */
SELECT prod_name, prod_price
FROM Products
WHERE prod_price BETWEEN 3 AND 6
ORDER BY prod_price ASC;
/** @nc code=end */
