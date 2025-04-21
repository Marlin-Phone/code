CREATE TABLE nowcoder_tbl(
    id INT PRIMARY KEY AUTO_INCREMENT,
    nowcoder_title VARCHAR(255),
    nowcoder_author VARCHAR(255),
    submission_date DATE
)

SELECT * FROM nowcoder_tbl WHERE nowcoder_author = "marlin_phone" OR id = 1;

update nowcoder_tbl 
set nowcoder_title = '学习 PHP'
where id = 1;

select * 
FROM nowcoder_tbl
WHERE nowcoder_title LIKE ''