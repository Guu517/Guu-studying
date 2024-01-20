class Student:
    def __init__(self,name,age,num): # init构造方法会自动执行
        self.name = name
        self.age = age
        self.num = num
for i in range(1,2):
    print(f"当前录入第{i}位学生信息")
    name = input("请输入学生姓名：")
    age = input("请输入学生年龄：")
    num = input("请输入学生学号：")
    stu = Student(name, age, num)
    print(f"学生{i}信息录入成功，信息为：【学生姓名：{stu.name},年龄：{stu.age},学号：{stu.num}】")