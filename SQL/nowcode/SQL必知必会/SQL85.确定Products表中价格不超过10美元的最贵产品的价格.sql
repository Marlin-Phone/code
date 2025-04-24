/**
 * @nc app=nowcoder id=19d1f06a58b04258aabe5a5a9934e611 topic=298 question=40362 lang=MySQL
 * 2025-04-24 14:29:13
 * https://www.nowcoder.com/practice/19d1f06a58b04258aabe5a5a9934e611?tpId=298&tqId=40362
 * [SQL85] 确定 Products 表中价格不超过 10 美元的最贵产品的价格
 */

/** @nc code=start */
SELECT MAX(prod_price) AS max_price
FROM Products
WHERE prod_price <= 10;


/** @nc code=end */
