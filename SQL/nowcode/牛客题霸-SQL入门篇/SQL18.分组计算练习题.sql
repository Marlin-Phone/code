/**
 * @nc app=nowcoder id=009d8067d2df47fea429afe2e7b9de45 topic=199 question=1975670 lang=MySQL
 * 2025-04-21 17:41:04
 * https://www.nowcoder.com/practice/009d8067d2df47fea429afe2e7b9de45?tpId=199&tqId=1975670
 * [SQL18] 分组计算练习题
 */

/** @nc code=start */
SELECT 
    gender, university, COUNT(gender) AS user_num, AVG(active_days_within_30) AS avg_active_day, AVG(question_cnt) AS avg_question_cnt
FROM user_profile
GROUP BY university, gender
ORDER BY gender ASC, university ASC;


/** @nc code=end */
