/**
 * @nc app=nowcoder id=e4268b4e044e4b94875c238098d98cf8 topic=298 question=40350 lang=MySQL
 * 2025-04-23 20:27:03
 * https://www.nowcoder.com/practice/e4268b4e044e4b94875c238098d98cf8?tpId=298&tqId=40350
 * [SQL73] 返回所有价格在 3美元到 6美元之间的产品的名称和价格
 */

/** @nc code=start */
SELECT prod_name, prod_price
FROM Products
WHERE prod_price BETWEEN 3 AND 6
ORDER BY prod_price ASC;


/** @nc code=end */
