# Simple Physics Engine  

## Introduction

这是 TDSG 开设的基础物理模拟入门课程所使用的代码框架，其中包含课程项目的完整实现 [main](https://github.com/TDS-Graphics/simple_physics_engine/tree/main) 分支，以及每个章独立的分支，所以你尽管你实现的代码和我们的不同也可以随时切换分支以同步我们的代码 ，或者你可以按照自己在课程中学习到的物理引擎核心算法思想自己实现。  

## Quick Start
Step 1: Clone 本仓库并安装依赖：
```shell
git clone --recurse-submodules https://github.com/TDS-Graphics/simple_physics_engine.git
cd simple_physics_engine
```
Step 2：Build 如果你是 Windows 系统，请确保跟随 (TODO) TDSG DOCS Website 中的 Windows C/C++ 开发环境配置 进行了环境配置  
```shell
cmake -B Build
cmake --build build
```
生成产物：

## Make A New Sample
我们的框架结构采用了类似于游戏引擎脚本形式，这并不是因为 Artichoke 熟悉游戏引擎架构，而是考虑到大多数使用物理引擎的场景就是在游戏引擎脚本中，所以 Artichoke 直接搭建了一个类似于游戏引擎脚本的结构（但区别还是很大），在其中使用我们自己开发的物理引擎搭建场景，做测试等等。

（TODO: 未来也许添加一个脚本，运行后自动创建一个 sample ，不需要手动创建了）
我们推荐的使用 simple_physics_engine 的形式是直接在根目录下的 samples 目录下创建一个类似与 hello_world sample 的 sample。  
而每个 sample 都可被编译为独立的可运行二进制程序，而使用 sample 的方式是因为这里已经完全配置好了基本的 CMake 代码，你只需要依葫芦画瓢就可以创建出一个新的自己的 sample 。

## About

我们采用了和 (TDSG-Raster-Lab)[https://github.com/TDS-Graphics/TDSG-Raster-Lab] 同样的开源证书 GPL v3.0

