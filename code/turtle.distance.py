import turtle
import math
x1,y1 = 100,100
x2,y2 = 100,-100
x3,y3 = -100,-100

turtle.penup()
turtle.goto(x1,y1)
turtle.pendown()
turtle.goto(x2,y2)
turtle.goto(x3,y3)

distance = math.sqrt((x1-x3)**2+(y1-y3)**2)
turtle.write(distance)
turtle.done()
