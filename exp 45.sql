CREATE DATABASE DB;
SHOW DATABASES;
USE DB;

    CREATE TABLE Animals(
    AID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    Animal VARCHAR(20) NOT NULL DEFAULT'',
    PRIMARY KEY(AID)
    );
    CREATE TABLE Foods(
    FID INT UNSIGNED NOT NULL AUTO_INCREMENT,
    Food VARCHAR(20) NOT NULL DEFAULT'',
    PRIMARY KEY(FID)
    );
SHOW TABLES;
INSERT INTO Animals(AID,Animal)values
   (1,'Cat'),
   (2,'Dog'),
   (3,'Cow');
INSERT INTO Foods(FID,Food)values
   (1,'Milk'),
   (2,'Bone'),
   (3,'Grass');   
SELECT * FROM Animals;   
SELECT * FROM Foods;
SELECT * FROM Animals CROSS JOIN Foods;
SELECT Animal,Food FROM Animals LEFT JOIN Foods ON Animals.AID = Foods.FID;
SELECT Animal,Food FROM Animals RIGHT JOIN Foods ON Animals.AID = Foods.FID;
SELECT Animal ,Food FROM Animals, Foods WHERE Animals.AID = Foods.FID ;
SELECT Animal,Food FROM Animals INNER JOIN Foods ON Animals.AID = Foods.FID;
    CREATE TABLE Employee(
    Empid INT UNSIGNED NOT NULL AUTO_INCREMENT,
    Name VARCHAR(20) NOT NULL DEFAULT'',
    mgrid CHAR(20) NOT NULL DEFAULT'',
    PRIMARY KEY(Empid)
    );
SHOW TABLES;    
INSERT INTO Employee(Empid,Name,mgrid)values
   (1,'Vyas',2),
   (2,'Tom',3),
   (3,'Mary',NULL),
   (4,'Laya',3);
SELECT * FROM Employee;
SELECT t1.Name , t2.Name FROM Employee AS t1, Employee AS t2 WHERE t1.mgrid = t2.Empid;