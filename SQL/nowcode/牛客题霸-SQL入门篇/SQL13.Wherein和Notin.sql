/**
 * @nc app=nowcoder id=0355033fc2244cdaa09b2bd6e794c762 topic=199 question=1975665 lang=MySQL
 * 2025-04-20 22:29:30
 * https://www.nowcoder.com/practice/0355033fc2244cdaa09b2bd6e794c762?tpId=199&tqId=1975665
 * [SQL13] Where in 和Not in
 */

/** @nc code=start */
SELECT device_id, gender, age, university, gpa
FROM user_profile
WHERE university = "北京大学" OR university = "山东大学" OR university = "复旦大学";


/** @nc code=end */
