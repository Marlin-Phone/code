/**
 * @nc app=nowcoder id=7d9a7b2d6b4241dbb5e5066d7549ca01 topic=199 question=1975669 lang=MySQL
 * 2025-04-20 22:40:12
 * https://www.nowcoder.com/practice/7d9a7b2d6b4241dbb5e5066d7549ca01?tpId=199&tqId=1975669
 * [SQL17] 计算男生人数以及平均GPA
 */

/** @nc code=start */
SELECT 
    COUNT(gender) as male_num,
    round(AVG(gpa), 1) as avg_gpa
FROM user_profile
WHERE gender = "male";


/** @nc code=end */
