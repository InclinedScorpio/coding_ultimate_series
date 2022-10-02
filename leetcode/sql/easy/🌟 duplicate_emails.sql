-- https://leetcode.com/problems/duplicate-emails/

/**
 * LOGIC: Basic
 *
 *
 */

select distinct(email) as 'Email' from Person as p where 1<>(select count(email) from Person as pin where p.email=pin.email);