def first_fist_algorithm(process_size, process, memory_block_size, memory_block):
    allocation = [-1] * process_size
    for i in range(process_size):
            for j in range(memory_block_size):
                if(memory_block[j] >= process[i]):
                    allocation[i] = j
                    memory_block[j] -= process[i]
                    break
    print process_size,
    for z in range(len(allocation)):
        print allocation[z],
    print memory_block_size,
    for k in range(memory_block_size):
        print memory_block[k],


memory_block_size = input()
memory_block = []
for i in range(memory_block_size):
    a  = input()
    memory_block.append(a)

process_size = input()
process = []
for j in range(process_size):
    b = input()
    process.append(b)

first_fist_algorithm(process_size,process,memory_block_size,memory_block)


