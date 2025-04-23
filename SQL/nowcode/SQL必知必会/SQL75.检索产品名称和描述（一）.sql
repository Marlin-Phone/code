/**
 * @nc app=nowcoder id=47e8101cb2b447038effcf5159e6aa7f topic=298 question=40352 lang=MySQL
 * 2025-04-23 22:23:08
 * https://www.nowcoder.com/practice/47e8101cb2b447038effcf5159e6aa7f?tpId=298&tqId=40352
 * [SQL75] 检索产品名称和描述（一）
 */

/** @nc code=start */
SELECT prod_name, prod_desc
FROM Products
WHERE prod_desc LIKE '%toy%'


/** @nc code=end */
