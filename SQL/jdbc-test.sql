CREATE DATABASE IF NOT EXISTS web01;

SHOW DATABASES;

USE web01;

SHOW TABLES;

create table user(
id int unsigned primary key auto_increment comment 'ID,主键',
username varchar(20) comment '用户名',
password varchar(32) comment '密码',
name varchar(10) comment '姓名',
age tinyint unsigned comment '年龄'
) comment '用户表';

SHOW TABLES;

insert into user(id, username, password, name, age) values (1, 'daqiao', '123456', '大乔', 22),
(2, 'xiaoqiao', '123456', '小乔', 18),
(3, 'diaochan', '123456', '貂蝉', 24),
(4, 'lvbu', '123456', '吕布', 28),
(5, 'zhaoyun', '12345678', '赵云', 27);

select * from user;