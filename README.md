# Sweep and Prune (SAP) Algorithm

This project implements the **Sweep and Prune (SAP)** broad-phase collision detection algorithm in C++. The algorithm efficiently identifies potential collision pairs by sorting and filtering axis-aligned bounding boxes (AABBs) along a specified axis.

## Features
- **SAP Algorithm**: Identify possible collision pairs using the Sweep and Prune method.
- **AABB Support**: Each object is represented by its axis-aligned bounding box (AABB).
- **Simple Modular Design**: The project is organized into modular components for better readability and extensibility.
- **Customizable**: Easily test with different AABB data and configurations.

## File Structure
```
sap_project/
├── sap.h           # Header file with data structures and function declarations
├── sap.cpp         # Implementation of the SAP algorithm
├── main.cpp        # Test file for validating the SAP algorithm
└── README.md       # Project description and usage instructions
```

## Getting Started

### Prerequisites
- **C++ Compiler**: A C++17-compatible compiler (e.g., GCC, Clang, MSVC).
- **Visual Studio** (optional): The project is set up for debugging and testing in Visual Studio.

### How to Build and Run
#### Using Visual Studio
1. Clone this repository:
   ```bash
   git clone https://github.com/your_username/sap_project.git
   ```
2. Open the solution file (`Sweep_and_Prune.sln`) in Visual Studio.
3. Ensure all source files (`sap.h`, `sap.cpp`, and `main.cpp`) are included in the project.
4. Build the project in **Debug** mode.
5. Press `F5` to run the program.

#### Using Command Line
1. Clone the repository:
   ```bash
   git clone https://github.com/your_username/sap_project.git
   cd sap_project
   ```
2. Compile the project:
   ```bash
   g++ -std=c++17 -o sap_test main.cpp sap.cpp
   ```
3. Run the executable:
   ```bash
   ./sap_test
   ```

### Example Output
For the sample AABB data provided in `main.cpp`, the output will be:
```
Potential Collision Pairs:
AABB 0 - AABB 1
AABB 1 - AABB 3
AABB 3 - AABB 2
```

## How It Works
1. **AABB Representation**:
   - Each object is represented by its axis-aligned bounding box, defined by minimum and maximum coordinates along each axis.
2. **Sweep and Prune**:
   - The algorithm sorts the AABBs along a specified axis.
   - It maintains an active list of AABBs and checks for overlaps along other axes to identify potential collision pairs.
3. **Efficient Filtering**:
   - By leveraging sorting and early rejection of non-overlapping AABBs, the algorithm minimizes unnecessary collision checks.

## File Details
- **sap.h**:
  - Contains data structures for AABB and SAP sorting points.
  - Declares the `sweepAndPrune` function.
- **sap.cpp**:
  - Implements the `sweepAndPrune` function, including sorting and overlap checks.
- **main.cpp**:
  - Provides a test case with sample AABBs to validate the algorithm.

## Future Enhancements
- Extend the algorithm to support dynamic objects.
- Add multi-threading support for larger datasets.
- Integrate with a physics engine for full collision detection pipelines.

## Contributing
Contributions are welcome! Feel free to fork the repository, submit issues, or open pull requests to improve this project.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments
- Inspired by the MuJoCo implementation of the SAP algorithm.
- Developed as part of a study on collision detection algorithms.
