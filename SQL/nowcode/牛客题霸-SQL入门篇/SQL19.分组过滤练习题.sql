/**
 * @nc app=nowcoder id=ddbcedcd9600403296038ee44a172f2d topic=199 question=1975671 lang=MySQL
 * 2025-04-23 15:53:57
 * https://www.nowcoder.com/practice/ddbcedcd9600403296038ee44a172f2d?tpId=199&tqId=1975671
 * [SQL19] 分组过滤练习题
 */

/** @nc code=start */
SELECT university, AVG(question_cnt) AS avg_question_cnt, AVG(answer_cnt) AS avg_answer_cnt
FROM user_profile
-- WHERE AVG(question_cnt) < 5 OR AVG(question_cnt) < 20
GROUP BY university
HAVING AVG(question_cnt) < 5 OR AVG(answer_cnt) < 20;

/** @nc code=end */