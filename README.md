# C++ 20 Udemy Course:

 https://www.udemy.com/course/the-modern-cpp-20-masterclass/learn/lecture/32787210#announcements

### Also note relevant course github: 

https://github.com/rutura/The-C-20-Masterclass-Source-Code



Other Resources for C++ and Competitive Programming:

- __Beginning C++20: From Novice to Professional__ (and the accompanying git repo: https://github.com/Apress/beginning-cpp20)
    - Ivor Horton, Peter Van Weert
- __Introduction to Algorithms, Third Edition__
    - Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein  
    - Note worked solutions available here: https://sites.math.rutgers.edu/~ajl213/CLRS/CLRS.html
- __Competitive Programmers Handbook__
    - Antti Laaksonen
    - https://cses.fi/book/book.pdf 
- learncpp.com
    - My personal favorite resource for quick C++ explanations
- https://en.cppreference.com/w/
- https://cplusplus.com/


 Problem Sets and/or Online Playgrounds:
 - https://leetcode.com/
 - https://www.hackerrank.com/dashboard
 - https://cses.fi/problemset/
 - https://projecteuler.net/
 - https://adventofcode.com/
 - https://codeforces.com/


# Important Notes:

- To use the MSVC compiler, we need to either add cl.exe to our path, or we can open VS Code from the Developer Powershell for VS 2022 via the command `code .`. 
    - I think alternatively you can go to View -> Command Palette -> C/C++ Edit  Configurations -> Compiler Path -> {full path to compiler}. This is also where you can define the C++ standard, Defines, change compiler, etc. You can save the configuration. Win32 is the default for Windows. 
    - Interesting [source](https://stackoverflow.com/questions/50830609/run-cl-exe-from-cmd) - seems like Microsoft releases a batch file which will update environment variables so you can avoid going through this `code .` step with Developer Powershell. But I think it's not recommended? Can read into this later. 
    - You can try your hand at downloading g++ and clang with a mingw64 distro, but it's not properly tooled for Windows, so you can find security concerns downloading them. I tried winlabs: https://winlibs.com/ (which the Udemy course suggests) and found threats. I'd rather not risk it personally.
- VS Code assigns the folder opened in the window as its workspace. In the tasks.json, we use `{workspaceFolder}` to specify where to find `*.cpp` files. There isn't any recursion on that, so if we want to use this build task, we have to open VS Code in the directory where all relevant source is located, or add additional arguments to the build task for a specific project. 
    - Alternatively, you can work on [CMake tutorials](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html) so you can properly learn the defacto tools for managing C++ projects.s 
