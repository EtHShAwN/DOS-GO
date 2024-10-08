# DOS-GO

**DOS-GO** is a lightweight DOS emulator designed to load and execute DOS programs. It provides basic functionality for executing some MS-DOS executables.

## Features

- **Program Loading**: 
  - Analyzes executable headers (currently only supports basic formats).
  - Allocates sufficient memory for program execution.
  - Emulates interrupts (basic support).

- **Instruction Execution**:
  - Supports the following CPU instructions:
    - `MOV`: Move data between registers.
    - `ADD`: Perform addition operations on registers.
    - `JMP`: Jump to different addresses in the program.

- **Memory Management**:
  - Allocates up to 640KB of RAM for program execution.

- **Future Enhancements**:
  - Support for loading `.EXE` files.
  - Implementation of additional graphical output capabilities.

## Requirements

- C Compiler (e.g., GCC)
- Makefile (optional, for easier builds)

## Getting Started

### Installation

1. Clone this repository:

   ```bash
   git clone https://github.com/phage-official/DOS-GO.git
   cd DOS-GO
   ```

2. Compile the source code:

   ```bash
   gcc -o dosgo main.c
   ```

### Usage

Run the emulator with an executable file as a command-line argument:

```bash
./dosgo your_program.bin
```

### Example Executable

You can write a simple binary file or use existing DOS programs that are compatible with the emulator's current implementation.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeature`).
3. Make your changes and commit them (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature/YourFeature`).
5. Open a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Thank you for your interest in DOS-GO!
