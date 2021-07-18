blocks = int(input("Enter the number of blocks: "))

#
# Write your code here.
#	

height = 0
total = 0

#if blocks > 0:
#    height = 1

while total < blocks:
    height = height + 1
    ###total = blocks - heigth
    total = total + height + 1

print("The height of the pyramid:", height)
