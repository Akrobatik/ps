for _ in range(0, 3):
  sum = 0
  n = int(input())
  for i in range(0, n):
    sum += int(input())
  if (sum == 0):
    print("0")
  elif (sum > 0):
    print("+")
  else:
    print("-")
