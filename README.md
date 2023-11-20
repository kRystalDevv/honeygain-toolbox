# Conversion Tool for Honeygain

Welcome to the Honeygain Conversion Tool! This simple command-line tool allows you to calculate rates and conversions for Honeygain, specifically for data sizes in megabytes, gigabytes, and points.

## Features:

1. **User-Friendly Interface:**
   The tool presents a straightforward menu interface, making it easy for users to choose the type of conversion they want to perform.

2. **Cross-Platform Compatibility:**
   Compatible with both Windows and Linux environments, ensuring a consistent user experience across different operating systems.

3. **Verbose Mode:**
   Activate verbose mode using the `-v` command-line option to enable additional information about the operating system.

4. **Clear Screen Functionality:**
   The tool utilizes platform-specific clear screen functions, ensuring a clean and organized display.

5. **IP Address Lookup (Windows/Linux):**
   For Windows users, the tool provides a quick lookup of the IPv4 address using `ipconfig`. For Linux users, the equivalent information is displayed using `ifconfig`.

6. **Conversion Options:**
   - **Megabytes to Points:** Convert the provided amount in megabytes to points, with an estimated value in dollars.
   - **Gigabytes to Points:** Convert the provided amount in gigabytes to points, with an estimated value in dollars.
   - **Direct Points Entry:** Enter an amount in points, providing an estimated value in dollars.

7. **Input Validation:**
   Robust input validation ensures that users are prompted until a valid input is provided, preventing errors from unexpected input.

## Usage:

### Installation:
1. Clone the repository to your local machine.
2. Compile the program using a C compiler.

   ```bash
   gcc conversion_tool.c -o conversion_tool
   ```

### Run the Program:
Windows:
```bash
conversion_tool.exe
```
Linux:
```bash
./conversion_tool
```

### Verbose Mode:
Enable verbose mode to get additional information about your operating system.
Windows:
```bash
conversion_tool.exe -v
```
Linux:
```bash
./conversion_tool -v
```
   
## Example: 
```bash
$ ./conversion_tool

===================
1. Use Megabytes
2. Use Gigabytes
3. Use Points -
===================

Choice: 1
Enter Amount in Megabytes: 50

Your points are 15.00
Estimated in Dollars: $0.015
```
