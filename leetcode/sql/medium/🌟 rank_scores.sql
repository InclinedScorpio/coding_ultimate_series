-- https://leetcode.com/problems/rank-scores/

/**
 * LOGIC: imp to understand the nested way of picking and comparing
 *
 *
 */
select score, (select count(distinct score) from Scores as sin where s.score<=sin.score) as 'rank' from Scores as s order by score desc;