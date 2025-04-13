-- 创建表（分号结束）
CREATE TABLE users (
    id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);  -- ← 注意这里的分号

-- 新语句开始（无逗号）
SELECT table_name 
FROM information_schema.tables 
WHERE table_schema = DATABASE();