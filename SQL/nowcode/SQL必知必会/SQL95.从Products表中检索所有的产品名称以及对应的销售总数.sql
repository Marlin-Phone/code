/**
 * @nc app=nowcoder id=2b289b78de1546f38fd24e17e56f1bec topic=298 question=40372 lang=MySQL
 * 2025-04-28 17:51:50
 * https://www.nowcoder.com/practice/2b289b78de1546f38fd24e17e56f1bec?tpId=298&tqId=40372
 * [SQL95] 从 Products 表中检索所有的产品名称以及对应的销售总数
 */

/** @nc code=start */
SELECT prod_name,(
    SELECT SUM(quantity)
    FROM OrderItems
    WHERE OrderItems.prod_id = Products.prod_id
    GROUP BY prod_id
    ) AS quant_sold
FROM Products;


/** @nc code=end */
