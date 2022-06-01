
CREATE DATABASE IF NOT EXISTS test_db; 
USE test_db; 
CREATE TABLE IF NOT EXISTS test (
    id INTEGER UNIQUE NOT NULL PRIMARY KEY, 
    str VARCHAR(255) NOT NULL
) Engine=InnoDB; 

INSERT INTO test (str) VALUES 
(0, 'astro'), 
(1, 'beta'), 
(2, 'chem'); 
