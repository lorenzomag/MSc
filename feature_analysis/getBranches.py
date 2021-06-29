fin = open("SignalClass.h")
fout = open("branches.txt", "w")

lines = []


for line in fin:
    if line not in lines:
        lines.append(line)

for line in lines:
    fout.write(line)

