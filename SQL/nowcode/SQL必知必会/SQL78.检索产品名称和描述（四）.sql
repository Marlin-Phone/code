/**
 * @nc app=nowcoder id=a9099944fa9c4cf0b7e406f22ee8c9a0 topic=298 question=40355 lang=MySQL
 * 2025-04-23 22:28:12
 * https://www.nowcoder.com/practice/a9099944fa9c4cf0b7e406f22ee8c9a0?tpId=298&tqId=40355
 * [SQL78] 检索产品名称和描述（四）
 */

/** @nc code=start */
SELECT prod_name, prod_desc
FROM Products
WHERE prod_desc LIKE "%toy%carrots%";


/** @nc code=end */
