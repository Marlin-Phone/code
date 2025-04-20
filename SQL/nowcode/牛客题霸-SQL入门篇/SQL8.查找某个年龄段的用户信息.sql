/**
 * @nc app=nowcoder id=be54223075cc43ceb20e4ce8a8e3e340 topic=199 question=1971603 lang=MySQL
 * 2025-04-20 22:20:46
 * https://www.nowcoder.com/practice/be54223075cc43ceb20e4ce8a8e3e340?tpId=199&tqId=1971603
 * [SQL8] 查找某个年龄段的用户信息
 */

/** @nc code=start */
SELECT device_id, gender, age
FROM user_profile
WHERE age >= 20 AND age <= 23;


/** @nc code=end */
