/**
 * @nc app=nowcoder id=25bcf6924eff417d90c8988f55675122 topic=199 question=1971821 lang=MySQL
 * 2025-04-20 22:28:00
 * https://www.nowcoder.com/practice/25bcf6924eff417d90c8988f55675122?tpId=199&tqId=1971821
 * [SQL12] 高级操作符练习(2）
 */

/** @nc code=start */
SELECT device_id, gender, age, university, gpa
FROM user_profile
WHERE university = "北京大学" OR gpa > 3.7;


/** @nc code=end */
