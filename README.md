# 🧩 Rubik Solver

✨ A Rubik's Cube solver project using C++! 🚀 This project is designed for those interested in problem-solving algorithms and C++ programming. The Rubik's Cube is one of the classic challenges in the world of puzzles and mathematical problems, and this program provides multiple features to let you interact with it.

## 📌 Features
- 🔄✨ Ability to rotate all faces (clockwise and counterclockwise) with dedicated functions
- 🎨📊 Displays the cube numerically along with a color guide for better understanding
- 🏗🛠️ Clean and modular structure for rotation functions and cube state changes, making it easier to develop and optimize
- 🎲🔀 Randomized cube state generation to increase challenge and test solving algorithms
- 📏📌 Color distribution analysis to ensure Rubik's Cube rules are maintained
- 🧠📖 Easy to learn for beginners and configurable for advanced users
- ⚡🎯 Fast execution with minimal dependencies

## 🚀 How to Run
To run the project, follow these steps:

```sh
git clone https://github.com/l6Ml6/Rubik.git
cd Rubik
g++ -o rubik Rubik.cpp
./rubik
```

✅ Ensure `g++` is installed on your system. If needed, you can install it using `sudo apt install g++` on Linux or by installing `MinGW` on Windows.

## 🎨 Color Guide
| Number | Color |
|------|------|
| 1️⃣  | 🟩 Green (Front Face) |
| 2️⃣  | ⚪ White (Top Face) |
| 3️⃣  | 🔴 Red (Left Face) |
| 4️⃣  | 🟠 Orange (Right Face) |
| 5️⃣  | 🔵 Blue (Bottom Face) |
| 6️⃣  | 🟡 Yellow (Back Face) |

## 📜 How It Works
Upon execution, the program follows these steps:
1. 🎲🔀 Generates a randomized Rubik's Cube configuration.
2. 🔄🖲️ Allows rotation of different faces, including both clockwise and counterclockwise moves.
3. 📊📋 Displays the final state of the cube, allowing users to analyze its condition.
4. 🎨📌 Provides a color guide and counts each color for better understanding.
5. 📜⚙️ Executes multiple random moves to increase the complexity of solving.

## 💡 Use Cases
🔹 Modify the code to rotate specific faces with custom commands.
🔹 Implement an automatic solver using popular algorithms like CFOP.
🔹 Use this project as a foundation for teaching programming and search algorithms.

## 👨‍💻 Developer
**Mohammadreza** ❤️ Passionate about coding and solving logical puzzles! 🤖

## 🎯 Future Plans
- 🔹⚡ Optimize the solving algorithm for better speed and accuracy
- 🔹📥 Add user input functionality to interactively rotate specific faces via text commands
- 🔹🤖 Implement an automatic solver using algorithms like CFOP and Kociemba
- 🔹📊 Develop a graphical system to visualize the Rubik's Cube in 3D for a better user experience
- 🔹🛠 Create a GUI-based version for non-technical users

✨ I’d appreciate a ⭐️ if you like this project! 🚀 Feel free to open an issue for suggestions or questions. 😊

