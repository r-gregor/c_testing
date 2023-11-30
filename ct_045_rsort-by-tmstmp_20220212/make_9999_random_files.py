import random

# bash commands:
# create testdir and cd into it
# run command:
# $> for FFF in $(python3 ../makef.py); do touch $FFF; done


for N in range (9999):
	last8 = random.randint(11111111,99999999)
	print(f"filename_{last8}.txt")

