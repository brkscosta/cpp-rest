# CPP Rest Quick Start

## Install developement tools

Install clangd clang-tidy clang-format and g++-9 compiler:

```bash
sudo apt install -y clang-tidy-15 clangd-15 clang-format-15 clang-format-15 g++-9
```

Create links:

```bash
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 9
```

```bash
sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-15 100
```

```bash
sudo update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-15 15
```

```bash
sudo update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-15 15
```

Install gdb for debugging:

```bash
sudo apt-get -y install gdb
```

## Configure and compile the project

The script `build.sh`🚀 will configure and build the project but if you want you may also want to add a `.env` file to define some cmake variables.

## Run  the project

There is a `launch.json` defined you can modify and ajust.

### Enjoy the project! Contributions are welcome!
