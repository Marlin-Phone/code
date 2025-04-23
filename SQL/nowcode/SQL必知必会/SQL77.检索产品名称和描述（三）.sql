/**
 * @nc app=nowcoder id=4302920bc3da44169a3ac458eb549d01 topic=298 question=40354 lang=MySQL
 * 2025-04-23 22:26:42
 * https://www.nowcoder.com/practice/4302920bc3da44169a3ac458eb549d01?tpId=298&tqId=40354
 * [SQL77] 检索产品名称和描述（三）
 */

/** @nc code=start */
SELECT prod_name, prod_desc
FROM Products
WHERE prod_desc LIKE '%toy%' AND prod_desc LIKE '%carrots%';


/** @nc code=end */
