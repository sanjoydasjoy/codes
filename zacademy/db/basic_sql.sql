row addition / deletion / modification

CREATE DATABASE XM2
USE XM2
CREATE TABLE SUB2 (
    id INT AUTO_INCREMENT PRIMARY KEY ,
    name VARCHAR(100),
    date_of_birth DATE
);

INSERT INTO SUB2 (name, date_of_birth)
VALUES
    ('SANJOY', '2001-10-16'),
    ('*', '2001-12-01');

INSERT INTO SUB2 (name, date_of_birth)
VALUES ('**', '2001-08-10'); ///ROW ADDITION 

DELETE FROM SUB2 WHERE id = 3; ///ROW DELETION

UPDATE SUB2
SET date_of_birth = '2001-09-16' ///ROW MODIFICATION
WHERE id = 1;


SELECT * FROM SUB2
