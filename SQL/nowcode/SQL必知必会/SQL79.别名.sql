/**
 * @nc app=nowcoder id=3a4ec448b6f74dc49f886692887aaf84 topic=298 question=40356 lang=MySQL
 * 2025-04-23 22:31:51
 * https://www.nowcoder.com/practice/3a4ec448b6f74dc49f886692887aaf84?tpId=298&tqId=40356
 * [SQL79] 别名
 */

/** @nc code=start */
SELECT vend_id, vend_name AS vname, vend_address AS vaddress, vend_city AS vcity
FROM Vendors
ORDER BY vend_name ASC;


/** @nc code=end */
