import re
import sys

str1 = "BBB.12345678.txt"
pat = "[^0-9]*([0-9]{8})[^0-9]"


subs = re.findall(pat, str1)
if subs:
	print(subs)
else:
	print("No match!")
