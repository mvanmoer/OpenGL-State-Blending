# OpenGL-State-Blending
Qt 5.5.1/OpenGL 4.2 app with options to change blending state.

On Windows use Qt 5.4, otherwise OpenGL linking is complicated.
Mac apparently wants GL 4.1, a quick and dirty fix is to change the version id in the shaders. 

Small app to help with reasoning about OpenGL state blending (as opposed to blending in a shader). There are more blend
state options and combinations available than I can keep straight in my head. 

The scene is simple, 3 billboard sprites: top, middle, and bottom. The top one is drawn first and in front, etc.

The GUI:
* GL_BLEND checkbox: glEnable/glDisable of GL_BLEND
* GL_DEPTH_TEST checkbox: glEnable/glDisable of GL_DEPTH_TEST
* pre-multiply alpha checkbox: Whether or not to pre-multiply the RGB components by the alpha value. 
* src factor menu: The src factor for the first argument of glBlendFunc and glBlendFuncSeparate
* dst factor menu: The dst factor for the second argument of glBlendFunc and glBlendFuncSeparate
* blend equation menu: The equation for glBlendEquation or the first argument of glBlendEquationSeparate
* separate blend func checkbox: toggles whether to use (glBlendFunc and glBlendEquation) or (glBlendFuncSeparate and glBlendEquationSeparate)
* src alpha factor menu: The src alpha factor for the third argument of glBlendFuncSeparate
* dst alpha factor menu: The dst alpha factor for the fourth argument of glBlendFuncSeparate
* separate equation menu: The equation for the second argument of glBlendEquationSeparate
* glClearColor, top color, middle color, bottom color, and glBlendColor buttons: launches a color dialog for setting respective colors.
* alpha sliders and spinboxes: sets the respective alphas as a percentage from 0% to 100%.
* GL_COLOR_LOGIC_OP checkbox: glEnable/glDisable GL_COLOR_LOGIC_OP.
* glLogicOp menu: The logic operatio for glLogicOp.

TODO:
- improve GUI layout
- switch to lowest common denominator OpenGL profile?
- add shader loading
- add texture file loading
- add images of notable state combinations

