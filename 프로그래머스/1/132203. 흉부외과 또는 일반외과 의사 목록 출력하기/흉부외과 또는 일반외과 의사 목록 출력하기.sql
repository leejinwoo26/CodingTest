-- 코드를 입력하세요
SELECT DR_NAME, DR_ID ,  MCDP_CD, date_format(HIRE_YMD,"%Y-%m-%d") AS HIRE_YMD 
from DOCTOR 
where MCDP_CD IN ('CS','GS')
ORDER BY HIRE_YMD DESC , DR_NAME ASC
