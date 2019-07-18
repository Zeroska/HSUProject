#!python3


def first_fist_algorithm(process_size, process, memory_block_size, memory_block):
    allocation = [-1] * process_size
    for i in range(process_size):
            for j in range(memory_block_size):
                if(memory_block[j] >= process[i]):
                    allocation[i] = j
                    memory_block[j] -= process[i]
                    break
    print(f"{process_size}", end = ' ')
    for z in range(len(allocation)):
        print(f"{allocation[z]}",end = ' ')
    print(f"{memory_block_size}", end = ' ')
    for k in range(memory_block_size):
        print(f"{memory_block[k]}",end = ' ')


memory_block_size = int(input())
memory_block = []
for i in range(memory_block_size):
    a  = int(input())
    memory_block.append(a)

process_size = int(input())
process = []
for j in range(process_size):
    b = int(input())
    process.append(b)

first_fist_algorithm(process_size,process,memory_block_size,memory_block)



