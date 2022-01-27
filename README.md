# Clipboard 📋
## A tiny wrapper around Windows' clipboard API

**Clipboard** is a tiny C++-style header-only wrapper class built upon Windows' clipboard API.  

## Features
- Get clipboard's contents
- Set clipboard's contents

> Note: this wrapper currently support Windows only.

## Getting started
To get the **clipboard** wrapper inside your project you'll just need to clone the repo & add the `include` folder in your project's includes.

Repository cloning:
```sh
git clone https://github.com/Kid0h/clipboard.git
```

Here's just an *example* of including the wrapper in a [CMake](https://cmake.org/) project:
```cmake
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "clipboard/include")
```

## License
None, you can do whatever you want with it, I guess.