CREATE DATABASE DBMS;
USE DBMS;
CREATE TABLE products ( 

   productID   INT  UNSIGNED NOT NULL AUTO_INCREMENT, 

   productCode CHAR(3)      NOT NULL DEFAULT ' ', 

   name        VARCHAR(30)  NOT NULL DEFAULT ' ', 

   quantity    INT  UNSIGNED NOT NULL DEFAULT 0, 

   price       DECIMAL(7,2)  NOT NULL DEFAULT 99999.99, 

   PRIMARY KEY (productID) 

   ); 

   CREATE TABLE product_details ( 

  productID INT UNSIGNED NOT NULL, 

  comment TEXT NULL );
  
SHOW TABLES;
SHOW CREATE TABLE products;
DESC products;

ALTER TABLE product_details ADD PRIMARY KEY(productID); 
DESC products;  
ALTER TABLE product_details ADD FOREIGN KEY(productID)REFERENCES products(productID);
DESC products;
  
INSERT INTO products VALUES (11249,'PEN', 'Pen Red',5000,1.23); 
INSERT INTO products   VALUES 

                       (NULL,'PEN', 'Pen Blue',8000,1.25), 

                       (NULL,'PEN', 'Pen Black',2000,1.25); 

  INSERT INTO products(productCode,name,quantity,price)VALUES 

                       ('PEC','Pencil 2B',10000,0.48), 

                       ('PEC','Pencil 2H',8000,0.49);

SELECT * FROM products;
SELECT name,price FROM products;
SELECT DISTINCT price FROM products;

SELECT name,price FROM products WHERE price <1.0;
SELECT name,quantity FROM products WHERE quantity <=2000;
SELECT name,price FROM products WHERE productCode ='PEN';
SELECT name FROM products WHERE name LIKE'P%';
SELECT price FROM products WHERE productCode LIKE'%N';

UPDATE products SET price = price * 1.1; 
SELECT * FROM products;
UPDATE products SET quantity = quantity - 1000 WHERE name = 'PEN BLUE'; 
SELECT * FROM products;
UPDATE products SET quantity = quantity + 50,price = 1.27 WHERE name = 'PEN BLACK';
SELECT * FROM products;

DELETE FROM products WHERE name like 'Pencil %'; 
SELECT * FROM products;
DELETE FROM PRODUCTS

SELECT * FROM products WHERE quantity >= 5000 AND name LIKE 'Pen %';
SELECT * FROM products WHERE quantity >= 5000 AND price < 1.24 AND name LIKE 'Pen %';
SELECT * FROM products;
SELECT * FROM products WHERE NOT (quantity >= 5000 AND name LIKE 'Pen %');

SELECT * FROM products WHERE name IN ('Pen Red','Pen Black');
SELECT * FROM products WHERE name NOT IN ('Pen Red','Pen Black');

SELECT * FROM products WHERE (price BETWEEN 1.0 AND 2.0) AND (quantity BETWEEN 1000 AND 2000);
SELECT * FROM products;
SELECT * FROM products WHERE (price NOT BETWEEN 1.0 AND 2.0) AND (quantity NOT BETWEEN 1000 AND 2000);

SELECT * FROM products WHERE name LIKE 'Pen %' ORDER BY price DESC;
SELECT * FROM products WHERE name LIKE 'Pen %' ORDER BY price DESC, quantity;
SELECT * FROM products ORDER BY productCode, productID;
SELECT * FROM products ORDER BY RAND();

SELECT COUNT(*) AS 'Count' FROM products;
SELECT MAX(price),MIN(price),AVG(price),STD(price),SUM(quantity) FROM products;

SELECT  * FROM products GROUP BY productCode;
SELECT productCode, COUNT(*) FROM products GROUP BY productCode;		
SELECT productCode, COUNT(*) AS count FROM products GROUP BY productCode ORDER BY count DESC;
SELECT productCode, MAX(price) AS 'Highest Price', MIN(price) AS 'Lowest Price' FROM products GROUP BY productCode;
SELECT productCode, MAX(price), MIN(price), AVG(price), STD(price), SUM(quantity) FROM products GROUP BY productCode;
SELECT productCode, MAX(price), MIN(price), CAST(AVG(price) AS DECIMAL(7,2)) AS 'Average', CAST(STD(price) AS DECIMAL(7,2)) AS 'StdDev', SUM(quantity) FROM products GROUP BY productCode;

SELECT productCode AS 'Product Code', COUNT(*) AS 'Count', AVG(price) AS 'Average' FROM products GROUP BY productCode HAVING Count>=3;










