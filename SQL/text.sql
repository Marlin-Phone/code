CREATE DATABASE egg;

USE egg;
CREATE TABLE eggs_record (
    id INT PRIMARY KEY AUTO_INCREMENT,
    egg_name VARCHAR(10) NOT NULL,
    sold DATE NULL
);

INSERT INTO egg.eggs_record (id, egg_name, sold)
VALUES (1, '鸡蛋', '2021-01-01');

INSERT INTO egg.eggs_record (id, egg_name, sold)
VALUES (2, '鸭蛋', '2021-02-01');


INSERT INTO egg.eggs_record (id, egg_name, sold)
VALUES (3, '荷包蛋', '2025-04-14');

INSERT INTO egg.eggs_record
VALUES (DEFAULT, '鹅蛋', '2021-05-01');

DELETE FROM egg.eggs_record
WHERE id = 19;

UPDATE egg.eggs_record
SET sold = '999-6-1'
WHERE id = 20;

SELECT * FROM egg.eggs_record;

SELECT * FROM egg.eggs_record;