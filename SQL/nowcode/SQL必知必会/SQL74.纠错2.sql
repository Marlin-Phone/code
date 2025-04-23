/**
 * @nc app=nowcoder id=ec773e81e8084d70bc62fd9012eabae5 topic=298 question=40351 lang=MySQL
 * 2025-04-23 20:29:52
 * https://www.nowcoder.com/practice/ec773e81e8084d70bc62fd9012eabae5?tpId=298&tqId=40351
 * [SQL74] 纠错2
 */

/** @nc code=start */
SELECT vend_name
FROM Vendors
WHERE vend_country = 'USA' AND vend_state = 'CA'
ORDER BY vend_name ASC;


/** @nc code=end */
