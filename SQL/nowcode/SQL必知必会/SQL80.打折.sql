/**
 * @nc app=nowcoder id=90bb4ccf41b24f3fa7e5f460ff6ee7cd topic=298 question=40357 lang=MySQL
 * 2025-04-24 14:12:31
 * https://www.nowcoder.com/practice/90bb4ccf41b24f3fa7e5f460ff6ee7cd?tpId=298&tqId=40357
 * [SQL80] 打折
 */

/** @nc code=start */
SELECT prod_id, prod_price, prod_price * 0.9 AS sale_price
FROM Products;


/** @nc code=end */
