# Building
WARNING: Local files paths in `main.cpp`. This will be changed once the initial graphics pipeline is finished. Change these paths to correctly load resources.
1. `mkdir build && cd build`
2. `cmake ..` or `cmake -D BUILD_WITH_TESTS=ON ..`
3. `make`
4. `bin/LovelyEngine` to run executable or `bin/LovelyEngineTest` to run tests

# LovelyEgine - Why public?
I normally keep my personal projects private, but I'm in the job market and want to provide this as a sample. This repo contains the source code, doxygen documentation, and tests.

# LovelyEngine - What is it?
While this repo and iteration of this project is new, I've been working on this project for over 5 years as a passion and learning project. To keep my design and development skills sharp, I work on this project after work, on weekends, etc. Often times when I come back to it, I'll restart the project (hence this recently created repo) with a fresh lens and stronger development skills from my career.

The LovelyEngine is an OpenGL game engine, using GLFW and GLAD for developing the graphics pipeline and an Entity Component System for managing objects. The raw software development skills come from my education and career, while the graphics and game engine knowledge comes from numerous books and websites, which are listed below. I've been developing game engines in my free time since high school, with a focus on growth and learning outside school and work.

# Screenshots
![ ](https://github.com/jallen98/LovelyEngine/blob/develop/res/Demos/light_demo.gif)
![ ](https://github.com/jallen98/LovelyEngine/blob/develop/res/Demos/cubes.PNG)

# References
- [Learn OpenGL](https://learnopengl.com)
My goto resource while developing the graphics pipeline
- [Learn OpenGL Print Edition](https://www.amazon.com/gp/product/9090332561/ref=as_li_tl?tag=joeydevries-20&ie=UTF8&linkId=7dc8cb69143266ce47e97e21350bbfff&geniuslink=true)
A physical book of the above website, that I purchased a few years ago and still use to this day. It's an excellent resource
- [SFML Game Development by Example](https://www.amazon.com/SFML-Development-Example-Raimondas-Pupius/dp/1785287346/ref=asc_df_1785287346/?tag=hyprod-20&linkCode=df0&hvadid=312140868236&hvpos=&hvnetw=g&hvrand=10245637400762425020&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9003344&hvtargid=pla-662180708592&psc=1)
This resource isn't used in this project, but I thought it was worth mentioning. I purchased it in high school to kick off this journey.
- [Projection Matrix Calculation](http://www.songho.ca/opengl/gl_projectionmatrix.html)
Useful resource for some projection matrix calculations

# Licenses
Special thanks to all libraries used in this project, their licenses and git repos are linked below
- [GLFW](https://github.com/glfw/glfw/blob/master/LICENSE.md) - ZLib License
- [GLAD](https://github.com/Dav1dde/glad/blob/glad2/LICENSE) - MIT License
- [stb_image](https://github.com/nothings/stb/blob/master/LICENSE) - MIT License
- [googletest](https://github.com/google/googletest/blob/main/LICENSE) - BSD3 License
