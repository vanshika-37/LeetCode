# Write your MySQL query statement below
SELECT*,
if(x+y>z and x+z>y and y+z>x, "Yes","No") as triangle
FROM triangle;