/**
 * @nc app=nowcoder id=d5ac4c878b63477fa5e5dfcb427d9102 topic=199 question=1975666 lang=MySQL
 * 2025-04-20 22:30:59
 * https://www.nowcoder.com/practice/d5ac4c878b63477fa5e5dfcb427d9102?tpId=199&tqId=1975666
 * [SQL14] 操作符混合运用
 */

/** @nc code=start */
SELECT device_id, gender, age, university, gpa
FROM user_profile
WHERE gpa > 3.5 AND university = "山东大学" OR gpa > 3.8 AND university = "复旦大学"
ORDER BY device_id ASC;


/** @nc code=end */
