# C++ Project Template

This Github repository is a template for C++ projects. *DO NOT FORK THIS
REPOSITORY*. You should use the 'Use this template' button to create a new
repository for your project, making a copy of it in your own Github account.
After instantiatinœg the template, you should clone your new repository to your
local machine and start working on your project, or use an online code editor 
like Github Codespaces that can work with the git repository directly. 


# IDE Setup

There are a few things to do to get your IDE working and start your project 


## Visual Studio Code

### Install Programs

You will need to install three programs

* [Visual Studio Code](https://code.visualstudio.com/download)

For Windows:
* [Build Tools For Visual Studio](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2022) 
* [Git](https://git-scm.com/downloads)

On Windows, the Build Tools For Visual Studio should also install CMake, but you may have
 to install [CMake](https://cmake.org/download/) directly.


For Mac:
* [XCode](https://developer.apple.com/support/xcode/)
* [CMake](https://cmake.org/download/)
* [Git](https://git-scm.com/downloads)

For Macs, you can also install these tools by:

* [Install Homebrew](https://docs.brew.sh/Installation)
* brew install gcc
* brew install cmake
* brew install git


### Use the Template, then Clone the Repo

From this repo, click the green 'Use This Template' button to create a new repo. 
The, in the new repo, you should have a green "<> Code" button. Click that, and
on the "Local" tab, copy the HTTPS url. 

Open Visual Studio Code, and in the startup window, you should see, under the
"Start" heading, "Clone Git Repository ...". Click that link, then at the top 
of the Visual Studio window, enter the Repo url in the text field. 

### Install Extensions

You should install this extension, by clicking on the puzzle-blocks icon on the left menu bar:

* C/C++ Extension Pack, from Microsoft. (ms-vscode.cpptools-extension-pack)

If you install this extension VSCode will also install its dependencies, and
you will end up with 5 additional extensions. Note that this is not the
Microsoft "C/C++" extention

### Other Configuration

You might get a pop up window asking you to set the CMake menu bar visibility. Set it 
to Visible.  If you don't get the popup, click on the Cmake Icon in the left side 
menu bar, the triangle with the wrench. Then click on the gear icon in the CMake panel. 
You should see a new file table labled "Settings", with a text box at the top with 
"@ext:ms-vscode.cmake-tools" in it. Add "Visibility" to it so it reads 
"@ext:ms-vscode.cmake-tools visibility", then set the visibility feature to "visible". 

You can also go into the file `.vscode/settings.json` and add the entry:

     "cmake.options.statusBarVisibility": "visible",

### Select a Kit

On the bottom button bar, you will see "No Kit Selected". Click that and select
a compiler. GCC is a good choice, but you can also install Clang



# Building and Running


In th bottom menu bar you should see "⚙ Build [all]". The "⚙ Build" is the build
button, and the "[all]" part is the target that gets built. Click the ⚙ Build
button to build everything in the project. ( The first time will also build the
Catch2 testing library, so it will take a while ) 

With the default project, if you click the [all] button, you will get ( at the
top of the screen ) options to check what will get built. The important targets
are: 

* all. Build everything
* p5 The executable for problem 5. The code for this is in `src/problem5.cpp`
* hw5_test. A test program. The code for this is in `test/treasure_tests.cpp`


Also at the bottom of the screen are the run buttons, A bug, and a play button.
Click one of them and you will get a menu at the top for running or debugging a
program. Click one and that name will appear in brackets at the bottom. Click
the button to run the target, or the target name in brackets to change it. 

# Project Setup 

( Do this once ) 

If you are using this template for a homework project, *you should create a new
repository for each homework assignment.* You should not use the same
repository for multiple assignments, and name the repository after the
assignment. For example, if you are working on homework 1, you should create a
new repository called `hw1` and instantiate this template in that repository.
If you are working on homework 2, you should create a new repository called
`hw2`.

After cloning the template, rename the project to the same name. Edit the root
`CMakeLists.txt`, seting the name in the in line ``project(<proj_name> CXX)``

# Adding Executables 

( Do this for each homework problem that has a seperate main() )

For most projects, your source projects will go in the ``src/`` directory. To
add a source file that will be executable, you will do two things. 

1. Add the ``.cpp`` file to the ``src/`` directory
2. Add a block for the executable in ``src/CMakeLists.txt``

To create the executable block, you can edit or copy the block that runs from
``Add An Executable`` to ``End Executable``. You will need to edit the name of
the program that will be gnerated from the source on the ``set(EXEC_NAME) ``
line, then add all of the source files ( usually only one ) on the
``add_executable`` line. 

If you need to add another executable, just copy the entire block and edit the
two lines. 


## Acknowledgements

This template, editied by Eric Busboom, is based on [ccp-template]
(https://github.com/joshpeterson/cpp-template) by Josh Peterson. Josh's
cpp-template is based on the [Hello CMake]
(https://github.com/arnemertz/hello_cmake) project from Arne Mertz.
