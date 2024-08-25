class SimpleVM:
    def __init__(self):
        self.memory = [0] * 256  # 256 bytes of memory
        self.registers = [0] * 4  # 4 general-purpose registers
        self.pc = 0  # the program counter

    def load_program(self, program):
        self.memory[:len(program)] = program

    def run(self):
        while self.pc < len(self.memory):
            instruction = self.memory[self.pc]
            if instruction == 1:  # ADD
                reg1 = self.memory[self.pc + 1]
                reg2 = self.memory[self.pc + 2]
                self.registers[reg1] += self.registers[reg2]
                self.pc += 3
            elif instruction == 2:  # PRINT
                reg = self.memory[self.pc + 1]
                print(self.registers[reg])
                self.pc += 2
            else:
                break

program = [1, 0, 1, 2, 0]  # ADD R0, R1; PRINT R0
vm = SimpleVM()
vm.load_program(program)
vm.registers[0] = 10
vm.registers[1] = 5
vm.run()