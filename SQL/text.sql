-- Created table---------------------------------------------------------------
CREATE Table `employee`(
    `emp_id` INT PRIMARY KEY,
    `name` VARCHAR(20),
    `birth_date` DATE,
    `sex` VARCHAR(1),
    `salary` INT,
    `branch_id` INT,
    `sup_id` INT
);

CREATE Table `branch`(
    `branch_id` INT PRIMARY KEY,
    `branch_name` VARCHAR(20),
    `manager_id` INT,
    Foreign Key (`manager_id`) REFERENCES `employee`(`emp_id`) ON DELETE SET NULL
)


ALTER Table `employee`
ADD FOREIGN KEY (`branch_id`) REFERENCES `branch`(`branch_id`)
ON DELETE SET NULL;

ALTER Table `employee`
ADD FOREIGN KEY (`sup_id`)
REFERENCES `employee`(`emp_id`)
ON DELETE SET NULL;

CREATE Table `client`(
    `client_id` INT PRIMARY KEY,
    `client_name` VARCHAR(20),
    `phone` varchar(20)
)

create table `work_with`(
    `emp_id` INT,
    `client_id` INT,
    `total_sales` INT,
    PRIMARY KEY (`emp_id`, `client_id`),
    Foreign Key (`emp_id`) REFERENCES `employee`(`emp_id`) ON DELETE CASCADE,
    Foreign Key (`client_id`) REFERENCES `client`(`client_id`) ON DELETE CASCADE
)

-- Insert data into tables ---------------------------------------------------
INSERT INTO `branch` VALUES (1, '研发', NULL);
INSERT INTO `branch` VALUES (2, '行政', NULL);
INSERT INTO `branch` VALUES (3, '资讯', NULL);

INSERT INTO `employee` VALUES(206, '小黄', '1998-10-08', 'F', 50000, 1, NULL);
INSERT INTO `employee` VALUES(207, '小绿', '1985-09-16', 'M', 29000, 2, 206);
INSERT INTO `employee` VALUES(208, '小黑', '2000-12-19', 'M', 35000, 3, 206);
INSERT INTO `employee` VALUES(209, '小白', '1997-01-22', 'F', 39000, 3, 207);
INSERT INTO `employee` VALUES(210, '小蓝', '1925-11-10', 'F', 84000, 1, 207);

UPDATE branch
SET manager_id = 208
WHERE branch_id = 3;

INSERT INTO client VALUES (400, '阿狗', '254354335');
INSERT INTO client VALUES (401, '阿猫', '25633899');
INSERT INTO client VALUES (402, '旺来', '45354345');
INSERT INTO client VALUES (403, '露西', '54354365');
INSERT INTO client VALUES (404, '艾瑞克', '18783782');

INSERT INTO work_with VALUES (206, 400, '70000');
INSERT INTO work_with VALUES (207, 401, '24000');
INSERT INTO work_with VALUES (208, 402, '9800');
INSERT INTO work_with VALUES (209, 403, '24000');
INSERT INTO work_with VALUES (210, 404, '87940');

-- --------------------------------------------------------------------------------

select *
FROM employee;

select *
FROM branch;

SELECT *
FROM client;

SELECT *
FROM work_with;

-- ----------------------------------------------------------------------------

SELECT * FROM employee;

SELECT * FROM client;

SELECT * 
FROM employee
ORDER BY salary;

SELECT * 
FROM employee 
ORDER BY salary DESC
LIMIT 3;

SELECT DISTINCT branch_id
FROM employee;

-- 聚合函数----------------------------------------------------------------------------------------

SELECT COUNT(*) FROM employee;

SELECT COUNT(*) 
FROM employee
WHERE sex = 'F' AND birth_date > '1970-01-01';

SELECT AVG(salary)
FROM employee;

SELECT SUM(salary)
FROM employee;

SELECT MAX(salary) FROM employee;

-- 万用字元----------------------------------------------------------------------------------------------

SELECT * FROM `client` WHERE `phone` LIKE '%354%';

SELECT * FROM client WHERE client_name LIKE '艾%';

SELECT *
FROM employee
WHERE birth_date LIKE '____-09-__';

-- union 联集 ------------------------------------------------------------

SELECT name FROM employee
UNION
SELECT client_name FROM client
UNION
SELECT branch_name FROM branch;

SELECT emp_id, `name`
FROM employee
UNION
SELECT client_id, client_name
FROM client;

SELECT employee.salary AS total_money
FROM employee
UNION
SELECT work_with.total_sales
FROM work_with;

-- join 连接 --------------------------------------------------------------------------------

INSERT INTO branch VALUES (4, '偷懒', NULL);

SELECT * 
FROM employee
JOIN branch
ON emp_id = manager_id;

SELECT employee.emp_id, employee.name, branch.branch_name
FROM employee LEFT JOIN branch
ON employee.emp_id = branch.manager_id;

SELECT 