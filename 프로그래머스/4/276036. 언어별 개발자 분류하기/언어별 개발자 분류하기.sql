WITH
  group_front_end AS (
    SELECT DISTINCT ID, EMAIL
    FROM developers d
    JOIN skillcodes s ON (d.skill_code & s.CODE) > 0 AND s.category = 'Front End'
  ),
  group_python AS (
    SELECT DISTINCT ID, EMAIL
    FROM developers d
    JOIN skillcodes s ON (d.skill_code & s.CODE) > 0 AND s.name = 'Python'
  ),
  group_Csharp AS (
    SELECT DISTINCT ID, EMAIL
    FROM developers d
    JOIN skillcodes s ON (d.skill_code & s.CODE) > 0 AND s.name = 'C#'
  ),
  group_a AS (
    SELECT 'A' as GRADE, ID, EMAIL
    FROM developers
    WHERE ID IN (SELECT ID FROM group_front_end) AND ID IN (SELECT ID FROM group_python)
  ),
  group_b AS (
    SELECT 'B' as GRADE, ID, EMAIL
    FROM developers
    WHERE ID IN (SELECT ID FROM group_Csharp) AND ID not in (select ID from group_a)
  ),
  group_c AS (
    SELECT 'C' as GRADE, ID, EMAIL
    FROM developers
    WHERE ID IN (SELECT ID FROM group_front_end) AND ID not in (select ID from group_a) AND ID not in (select ID from group_b)
  )


SELECT * FROM group_a 
UNION 
SELECT * FROM group_b 
UNION 
SELECT * FROM group_c
ORDER BY 1, 2;
