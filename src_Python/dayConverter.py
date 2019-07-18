question = [2, 1, 4, 5, 7, 3, 7 ,8 ,9, 6]
length = []
trace = []

# check point at start and end
question.insert(0, -1)
question.append(99999)

# init data
for i in range(0, len(question)):
    print(i)
    length.append(0)
    trace.append(-1)

# the last number always have length is 1
length[len(length)-1] = 1

# start run from n - 1 to 0, n is 99999
for i in range(len(question) - 2, -1, -1):
    if question[i] <= question[i+1]:
        length[i] = length[i+1] + 1
        trace[i] = i + 1
    else:
        for j in range(i + 1, len(question)):
            if question[i] <= question[j]:
                length[i] = length[j] + 1
                trace[i] = j
                break
print(question)
print(length)
print(trace)

start = trace[0]
string_need = ""
while trace[start] != -1:
    string_need = string_need + str(question[start]) + " "
    start = trace[start]
print(string_need)