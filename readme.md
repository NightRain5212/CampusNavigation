
---

# 校园导航系统 (Campus Navigation System)

这是一个基于 C++ 和 Qt 框架开发的桌面应用程序，旨在提供一个可视化的校园导航解决方案。用户可以通过这个系统方便地查询校园内的地点信息、路径，并对地图数据进行管理。

## 🌟 功能特性

* **地点管理**:
    * 添加新的校园地点（如教学楼、图书馆、食堂等）。
    * 删除已有的地点。
    * 更新地点信息。
    * 按名称或类型查询地点。

* **路径管理**:
    * 在两个地点之间添加路径（边）。
    * 删除已有的路径。
    * 更新路径信息（如路径长度、拥挤程度等）。
    * 查询特定路径。

* **智能导航**:
    * 计算并显示两个地点之间的最短路径。
    * 可以根据时间等因素进行路径规划。

* **可视化界面**:
    * 使用 Qt Widgets 提供了用户友好的图形界面。
    * 通过对话框的形式进行所有交互操作，简单直观。

## 🛠️ 技术栈

* **核心语言**: C++
* **图形界面**: Qt 6
* **构建系统**: CMake
* **核心数据结构**: 图 (Graph) - 用于表示校园的地点和路径网络。

## 🚀 开始使用

### 依赖环境

在开始之前，请确保您的开发环境中已经安装了以下软件：

* C++ 编译器 (支持 C++17 或更高标准)
* CMake (3.5 或更高版本)
* Qt (6.x.x 版本)

### 编译与运行

1.  **克隆仓库**
    ```bash
    git clone <your-repository-url>
    cd CampusNavigation
    ```

2.  **创建构建目录**
    ```bash
    mkdir build
    cd build
    ```

3.  **配置项目 (CMake)**
    ```bash
    # 请根据您的实际 Qt 安装路径进行修改
    cmake .. -DCMAKE_PREFIX_PATH=/path/to/your/Qt/6.x.x/mingw_64
    ```

4.  **构建项目**
    ```bash
    cmake --build .
    ```

5.  **运行程序**
    构建成功后，在 `build` 目录下会生成可执行文件 `CampusNavigation.exe` (Windows) 或 `CampusNavigation` (Linux/macOS)。直接运行即可。

    ```bash
    ./CampusNavigation
    ```

- 注: windos下可以下载release压缩包解压后即可打开使用。
## 📖 使用说明

启动应用程序后，您会看到一个主窗口。通过菜单栏或工具栏的按钮，您可以执行以下操作：

* **添加/删除/更新地点**: 打开相应的对话框，输入地点信息（名称、类型等）来管理校园中的地点。
* **添加/删除/更新路径**: 打开相应的对话框，选择起点和终点，并输入路径信息来管理地点之间的连接。
* **查询地点/路径**: 使用查询功能快速找到您感兴趣的地点或路径。
* **查找最短路径**: 打开最短路径对话框，选择您的起点和终点，程序将会为您计算出最优的通行路径。

## 📁 项目结构

```
CampusNavigation/
├── CMakeLists.txt              # CMake 配置文件
├── main.cpp                    # 主函数入口
├── mainwindow.h                # 主窗口头文件
├── mainwindow.cpp              # 主窗口实现
├── graph.h                     # 图数据结构头文件
├── graph.cpp                   # 图数据结构实现
├── addedgedialog.h/cpp         # 添加路径对话框
├── addplacedialog.h/cpp        # 添加地点对话框
├── deledgedialog.h/cpp         # 删除路径对话框
├── delplacedialog.h/cpp        # 删除地点对话框
├── updateedgedialog.h/cpp      # 更新路径对话框
├── updateplacedialog.h/cpp     # 更新地点对话框
├── searchedgedialog.h/cpp      # 搜索路径对话框
├── searchplacebynamedialog.h/cpp # 按名称搜索地点对话框
├── searchplacebytypedialog.h/cpp # 按类型搜索地点对话框
├── searchbytimedialog.h/cpp    # 按时间搜索对话框
├── shortestpathdialog.h/cpp    # 最短路径对话框
├── report.md                   # 项目报告
└── build/                      # 构建目录
```

