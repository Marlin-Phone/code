/**
 * @nc app=nowcoder id=2d2e37474197488fbdf8f9206f66651c topic=199 question=1971781 lang=MySQL
 * 2025-04-20 22:25:23
 * https://www.nowcoder.com/practice/2d2e37474197488fbdf8f9206f66651c?tpId=199&tqId=1971781
 * [SQL11] 高级操作符练习(1)
 */

/** @nc code=start */
SELECT device_id, gender, age, university, gpa
FROM user_profile
WHERE gender = "male" AND gpa > 3.5;


/** @nc code=end */
