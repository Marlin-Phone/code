/**
 * @nc app=nowcoder id=669913837a7648f9aa0caaf6a88c834f topic=298 question=40353 lang=MySQL
 * 2025-04-23 22:24:53
 * https://www.nowcoder.com/practice/669913837a7648f9aa0caaf6a88c834f?tpId=298&tqId=40353
 * [SQL76] 检索产品名称和描述（二）
 */

/** @nc code=start */
SELECT prod_name, prod_desc
FROM Products
WHERE prod_desc NOT LIKE '%toy%'
ORDER BY prod_name ASC;
/** @nc code=end */
