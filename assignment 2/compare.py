import difflib

file = open('compare', 'r')
line1=file.readline()
line2=file.readline()
output_list = [li for li in difflib.ndiff(line1, line2) if li[0] != ' ']
print(output_list)