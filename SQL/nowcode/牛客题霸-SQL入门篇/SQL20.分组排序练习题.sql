/**
 * @nc app=nowcoder id=e00bbac732cb4b6bbc62a52b930cb15e topic=199 question=1975672 lang=MySQL
 * 2025-04-23 16:08:20
 * https://www.nowcoder.com/practice/e00bbac732cb4b6bbc62a52b930cb15e?tpId=199&tqId=1975672
 * [SQL20] 分组排序练习题
 */

/** @nc code=start */
SELECT university, AVG(question_cnt) AS avg_question_cnt
FROM user_profile
GROUP BY university
ORDER BY avg_question_cnt ASC;


/** @nc code=end */
