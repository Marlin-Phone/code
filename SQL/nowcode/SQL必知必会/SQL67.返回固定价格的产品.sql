/**
 * @nc app=nowcoder id=9949bfb933614abe8bd2bc26c129843e topic=298 question=40344 lang=MySQL
 * 2025-04-23 19:56:18
 * https://www.nowcoder.com/practice/9949bfb933614abe8bd2bc26c129843e?tpId=298&tqId=40344
 * [SQL67] 返回固定价格的产品
 */

/** @nc code=start */
SELECT prod_id, prod_name
FROM Products
WHERE prod_price = 9.49;


/** @nc code=end */
