/**
 * @nc app=nowcoder id=7858f3e234bc4d85b81b9a6c3926f49f topic=199 question=1971248 lang=MySQL
 * 2025-04-20 22:17:48
 * https://www.nowcoder.com/practice/7858f3e234bc4d85b81b9a6c3926f49f?tpId=199&tqId=1971248
 * [SQL6] 查找学校是北大的学生信息
 */

/** @nc code=start */
SELECT device_id, university
FROM user_profile
WHERE university = "北京大学"


/** @nc code=end */
