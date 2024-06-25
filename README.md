# C++ 20 Udemy Course:

 https://www.udemy.com/course/the-modern-cpp-20-masterclass/learn/lecture/32787210#announcements

### Also note relevant course github: 

https://github.com/rutura/The-C-20-Masterclass-Source-Code




# Important Notes:

- To use the MSVC compiler, we need to either add cl.exe to our path, or we can open VS Code from the Developer Powershell for VS 2022 via the command `code .`. 
    - I think alternatively you can go to View -> Command Palette -> C/C++ Edit  Configurations -> Compiler Path -> {full path to compiler}. This is also where you can define the C++ standard, Defines, change compiler, etc. You can save the configuration. Win32 is the default for Windows. 
- VS Code assigns the folder opened in the window as its workspace. In the tasks.json, we use `{workspaceFolder}` to specify where to find `*.cpp` files. There isn't any recursion on that, so if we want to use this build task, we have to open VS Code in the directory where all relevant source is located, or add additional arguments to the build task for a specific project. 
    - Alternatively, you can work on [CMake tutorials](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html) so you can properly learn the defacto tools for managing C++ projects.s 