/**
 * @nc app=nowcoder id=c12a056497404d1ea782308a7b821f9c topic=199 question=1971604 lang=MySQL
 * 2025-04-20 22:21:49
 * https://www.nowcoder.com/practice/c12a056497404d1ea782308a7b821f9c?tpId=199&tqId=1971604
 * [SQL9] 查找除复旦大学的用户信息
 */

/** @nc code=start */
SELECT device_id, gender, age, university
FROM user_profile
WHERE university != "复旦大学"


/** @nc code=end */
