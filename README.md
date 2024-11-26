# Environmental Solutions Management System
![5d540b77-3524-4993-b4c9-958c7619d12e](https://github.com/user-attachments/assets/9f612f40-fbd2-4344-b809-6f83cc44ce02)


## Description
The Environmental Solutions Management System is a software solution developed to support a startup focused on managing industrial waste and emissions. Built using the C programming language, this project applies modular design principles and software engineering techniques to ensure maintainability, scalability, and security.

The system offers industry registration, waste treatment tracking, and report generation to facilitate comprehensive environmental management for industries. It ensures compliance with the Brazilian General Data Protection Law (LGPD) by implementing encryption for sensitive data and robust user authentication.

## Features
- **User Authentication**: Secure login using password hashing (SHA-256) and input validation.
- **Industry Registration**: Detailed recording of industry data, including contact and location information.
- **Waste Tracking**: Monthly updates for tracking waste treatment data and associated costs.
- **Report Generation**: Customizable reports for individual and global analysis, exportable in multiple formats.
- **Data Security**: Encryption for data at rest and in transit, ensuring compliance with privacy regulations.

## Getting Started

### Prerequisites
- GCC compiler for C language.
- A terminal to run the application.

### Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/stain19/environmental_solutions_management.git
   ```
2. Navigate to the project directory:
   ```sh
   cd environmental-solutions-management
   ```
3. Compile the project:
   ```sh
    make
   ```
4. Run the project
   ```sh
   make run_program
   ```

### Usage
1. Run the executable:
   ```sh
   ./bin/program
   ```
2. Follow the on-screen instructions to log in, register industries, track waste, and generate reports.

## Project Structure
- `main.c` - Entry point of the application.
- `login.c` - Handles user authentication logic.
- `tela-menu-industrias.c` - Manages the industry registration menu.
- `tela-menu-insumos.c` - Handles waste tracking and insumos data.
- `repository_industrias.c` - Handles data persistence for industries.

## Security Measures
- Passwords are hashed with SHA-256 before storage to ensure confidentiality.
- Input validation to prevent buffer overflow attacks.
- Limitation on error messages to prevent information disclosure during login attempts.

## Contributing
Feel free to submit issues or pull requests to help improve the project. Contributions are always welcome!

## License
This project is licensed under the MIT License. See `LICENSE` for more information.

## Acknowledgements
- Professors and mentors for guidance throughout the development.
- Open source libraries and resources used for encryption and software best practices.

---

The Environmental Solutions Management System aims to automate processes, ensure environmental compliance, and enhance the efficiency of managing industrial waste for a more sustainable future.
