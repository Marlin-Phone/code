/**
 * @nc app=nowcoder id=f6153be7485448cdb444279dcc105cb8 topic=298 question=40345 lang=MySQL
 * 2025-04-23 19:58:02
 * https://www.nowcoder.com/practice/f6153be7485448cdb444279dcc105cb8?tpId=298&tqId=40345
 * [SQL68] 返回更高价格的产品
 */

/** @nc code=start */
SELECT prod_id, prod_name
FROM Products
WHERE prod_price >= 9;


/** @nc code=end */
