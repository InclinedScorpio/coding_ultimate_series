-- https://leetcode.com/problems/nth-highest-salary/

/**
 * LOGIC: Important to check the Declaration of variable and setting up variables
 *
 */
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE NUM INT;
  SET NUM=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select salary as getNthHighestSalary from Employee group by salary order by salary desc limit NUM, 1
  );
END

-- OR 

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE NUM INT;
  SET NUM=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct salary from Employee order by salary desc limit NUM, 1
  );
END