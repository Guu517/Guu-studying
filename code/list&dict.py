r1 = {'name':'辜艺淇','age':18,'city':'潮州'}
r2 = {'name':'辜二淇','age':17,'city':'广州'}
r3 = {'name':'辜三淇','age':16,'city':'上海'}

R = [r1,r2,r3]
print(R)

for i in range(len(R)):
    print(R[i].get('name'),R[i].get('age'),R[i].get('city'))
