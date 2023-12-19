# CPP Rest Quick Start

## Install developement tools

- Install clangd language server and clang-format and g++ 9.5.0

For clangd check the steps:

```bash
sudo apt install -y clangd-15 clang-format-15 g++-9
```

```bash
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 9
```

```bash
sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-15 100
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
