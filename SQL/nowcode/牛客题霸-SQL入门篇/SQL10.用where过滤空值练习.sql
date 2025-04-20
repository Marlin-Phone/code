/**
 * @nc app=nowcoder id=08c9846a423540319eea4be44e339e35 topic=199 question=1971605 lang=MySQL
 * 2025-04-20 22:22:50
 * https://www.nowcoder.com/practice/08c9846a423540319eea4be44e339e35?tpId=199&tqId=1971605
 * [SQL10] 用where过滤空值练习
 */

/** @nc code=start */
SELECT device_id, gender, age, university
FROM user_profile
WHERE age IS NOT NULL;


/** @nc code=end */
