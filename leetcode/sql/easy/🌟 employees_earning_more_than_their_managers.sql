-- https://leetcode.com/problems/employees-earning-more-than-their-managers/

/**
 * LOGIC: Imp to know joins
 *
 */
select e.name as 'Employee' from Employee e 
    inner join Employee m
        on e.managerId=m.id
    where e.salary>m.salary;