
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

INSERT INTO `employee`

select *
FROM employee;

select *
FROM branch;