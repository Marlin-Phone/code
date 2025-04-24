/**
 * @nc app=nowcoder id=7cbf5e3082954c21a80fc750ce97350f topic=298 question=40358 lang=MySQL
 * 2025-04-24 14:15:09
 * https://www.nowcoder.com/practice/7cbf5e3082954c21a80fc750ce97350f?tpId=298&tqId=40358
 * [SQL81] 顾客登录名
 */

/** @nc code=start */
SELECT cust_id, cust_name, 
UPPER(CONCAT(SUBSTRING(cust_name, 1, 2), SUBSTRING(cust_city, 1, 3))) AS user_login
FROM Customers;


/** @nc code=end */
