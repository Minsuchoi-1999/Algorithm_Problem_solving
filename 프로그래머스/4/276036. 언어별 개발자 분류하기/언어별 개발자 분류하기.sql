# A : Front End 스킬과 Python 스킬을 함께 가지고 있는 개발자
# B : C# 스킬을 가진 개발자
# C : 그 외의 Front End 개발자

# 일단 하나씩 구해보자
with a_grade as (
    select "A" grade, d.*
    from developers d
    where skill_code & (
        select sum(code) 
        from skillcodes 
        where category = 'Front End' 
        group by category
    )
        and skill_code & (
            select code 
            from skillcodes 
            where name = 'Python'
    )
), b_grade as (
    select "B" grade, d.*
    from developers d
    where skill_code & (
        select code 
        from skillcodes 
        where name = 'C#'
        and d.id not in (select id from a_grade)
    )
), c_grade as (
    select "C" grade, d.*
    from developers d
    where skill_code & (
        select sum(code)
        from skillcodes
        where category = 'Front End'
        group by category
    ) and d.id not in (select id from a_grade) and d.id not in (select id from b_grade)
)

select u.grade, u.id, u.email
from (
    select * from a_grade
    union
    select * from b_grade
    union
    select * from c_grade
) u
order by u.grade, u.id;