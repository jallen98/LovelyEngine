# Building and Running
1. `mkdir build && cd build`
2. `cmake ..` or `cmake -D BUILD_WITH_TESTS=ON ..`
3. `make`
4. Running requires providing the absolulte path to the `res` directory of this repo    
   a. For example `bin/LovelyEngine /home/jallen/LovelyEngine/res`    
   b. or `bin/LovelyEngineTest` to run tests

# Screenshots
![ ](https://github.com/jallen98/LovelyEngine/blob/develop/docs/Demos/cubes.PNG)
![ ](https://github.com/jallen98/LovelyEngine/blob/develop/docs/Demos/light_demo.gif)
![ ](https://github.com/jallen98/LovelyEngine/blob/develop/docs/Demos/multiple_lights.gif)

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
