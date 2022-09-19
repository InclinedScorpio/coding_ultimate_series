-- https://leetcode.com/problems/second-highest-salary/

/**
 * LOGIC: Problem is getting null as just doing `select distinct salary as SecondHighestSalary from ....` won't fetch us null
 * - Hence to get the NULL we need that outer select statement.
 *
 */
select(select distinct salary from Employee order by salary desc limit 1, 1) as SecondHighestSalary;

-- Another solution
/**
 * LOGIC: Here we are using max() hence it returns NULL if no data exists hence we no need outer select statement here
 */
select max(salary) as SecondHighestSalary from Employee where salary not in (select max(salary) from Employee);

