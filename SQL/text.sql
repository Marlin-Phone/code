CREATE TABLE nowcoder_tbl(
    id INT PRIMARY KEY AUTO_INCREMENT,
    nowcoder_title VARCHAR(255),
    nowcoder_author VARCHAR(255),
    submission_date DATE
)

INSERT INTO nowcoder_tbl(nowcoder_title, nowcoder_author, submission_date)
VALUES("学习 PHP", "牛客教程", NOW());

INSERT INTO nowcoder_tbl(nowcoder_title, nowcoder_author, submission_date)
VALUES("text", "marlin_phone", NOW());

SELECT * FROM nowcoder_tbl WHERE nowcoder_author = "marlin_phone" OR id = 1;
