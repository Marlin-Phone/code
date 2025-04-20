/**
 * @nc app=nowcoder id=39f74706f8d94d37865a82ffb7ba67d3 topic=199 question=2002633 lang=MySQL
 * 2025-04-20 22:15:10
 * https://www.nowcoder.com/practice/39f74706f8d94d37865a82ffb7ba67d3?tpId=199&tqId=2002633
 * [SQL37] 查找后多列排序
 */

/** @nc code=start */
SELECT device_id, gpa, age
FROM user_profile
ORDER BY gpa ASC, age ASC;


/** @nc code=end */
