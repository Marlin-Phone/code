/**
 * @nc app=nowcoder id=d023ae0191e0414ca1b19451099a39f1 topic=199 question=2002634 lang=MySQL
 * 2025-04-20 22:16:26
 * https://www.nowcoder.com/practice/d023ae0191e0414ca1b19451099a39f1?tpId=199&tqId=2002634
 * [SQL38] 查找后降序排列
 */

/** @nc code=start */
SELECT device_id, gpa, age
FROM user_profile
ORDER BY gpa DESC, age DESC;


/** @nc code=end */
