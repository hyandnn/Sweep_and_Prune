# Sweep and Prune (SAP) Broad-Phase Algorithm

This project implements a **Sweep and Prune (SAP)** broad-phase collision detection algorithm in C++. It identifies potential collision pairs by sorting and filtering axis-aligned bounding boxes (AABBs) along specified axes. The implementation is modular and extensible, designed to handle both simple and moderately complex collision detection tasks.

## Features
- **Broad-Phase SAP**:
  - Efficiently identifies potential collision pairs using the Sweep and Prune algorithm.
  - Implements axis-based sorting and active list filtering.
- **AABB Representation**:
  - Each object is represented as an axis-aligned bounding box (AABB) for simplicity and efficiency.
- **Modular Design**:
  - Organized into independent components for data structures, core algorithms, and testing.
- **Extensibility**:
  - Ready for future integration with dynamic objects and flexible datasets.

## File Structure
```
sap_broadphase/
├── include/
│   ├── AABB.h            # AABB data structures and utility function declarations
│   ├── SAP.h             # SAP algorithm declarations
│   ├── BroadPhase.h      # Broad-phase main logic declarations
├── src/
│   ├── AABB.cpp          # Implementation of AABB utility functions
│   ├── SAP.cpp           # Implementation of the SAP algorithm
│   ├── BroadPhase.cpp    # Implementation of broad-phase logic
├── main.cpp              # Test file for validating the full pipeline
├── README.md             # Project description and usage instructions
```

## Getting Started

### Prerequisites
- **C++ Compiler**:
  - A C++17-compatible compiler (e.g., GCC, Clang, MSVC).
- **Build Tools**:
  - Visual Studio (recommended) or other IDEs with C++17 support.
- **Git**:
  - Required for cloning the repository.

### How to Build and Run
#### Using Visual Studio
1. Clone this repository:
   ```bash
   git clone https://github.com/your_username/sap_broadphase.git
   ```
2. Open the solution file (`Sweep_and_Prune.sln`) in Visual Studio.
3. Add all source files (`AABB.h/cpp`, `SAP.h/cpp`, `BroadPhase.h/cpp`, and `main.cpp`) to the project if not already included.
4. Build the project in **Debug** or **Release** mode.
5. Press `F5` to run the program.

#### Using Command Line
1. Clone the repository:
   ```bash
   git clone https://github.com/your_username/sap_broadphase.git
   cd sap_broadphase
   ```
2. Compile the project:
   ```bash
   g++ -std=c++17 -o sap_broadphase_test src/*.cpp
   ```
3. Run the executable:
   ```bash
   ./sap_broadphase_test
   ```

### Example Output
For the sample AABB data provided in `main.cpp`, the output will look like this:
```
Potential Collision Pairs:
AABB 0 - AABB 1
AABB 1 - AABB 3
AABB 3 - AABB 2
```

## How It Works
1. **AABB Representation**:
   - Objects are represented by their axis-aligned bounding boxes (AABBs), defined by minimum and maximum coordinates along each axis.
2. **SAP Algorithm**:
   - AABBs are sorted along a specified axis.
   - An active list tracks overlapping AABBs during a sweep, identifying potential collision pairs.
3. **Broad-Phase Logic**:
   - SAP is executed along all three axes (x, y, z) for thorough detection.
   - Duplicates are removed from the final collision pair list.

## File Details
- **AABB.h/cpp**:
  - Contains the `AABB` structure and utility functions for overlap checking.
- **SAP.h/cpp**:
  - Implements the Sweep and Prune algorithm, including sorting and active list management.
- **BroadPhase.h/cpp**:
  - Combines SAP with multi-axis detection for comprehensive broad-phase collision detection.
- **main.cpp**:
  - Provides a test harness to validate the entire pipeline with example data.

## Future Enhancements
- **Dynamic Object Support**:
  - Extend the algorithm to handle real-time updates of AABBs in dynamic scenes.
- **Parallelization**:
  - Use multi-threading or GPU acceleration for large datasets.
- **Integration with Physics Engines**:
  - Adapt the algorithm for integration into real-world physics engines or simulation environments.
- **Flex Body Handling**:
  - Add support for flexible bodies or deformable objects.

## Contributing
Contributions are welcome! Please:
1. Fork the repository.
2. Create a feature branch.
3. Submit a pull request with a detailed description of your changes.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments
- Inspired by the broad-phase collision detection implementation in [MuJoCo](https://mujoco.org/).
- Developed as part of a study on efficient collision detection algorithms for robotics and simulations.
