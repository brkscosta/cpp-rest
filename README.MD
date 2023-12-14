# CPP Rest Quick Start

## Install developement tools

- Install clangd language server and clang-format and g++ 9.5.0

For clangd check the steps:

```bash
sudo apt install -y clangd-15 clang-format-15
```

```bash
sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-15 100
```

Install gdb for debugging:

```bash
sudo apt-get -y install gdb
```


## Install project dependecy

```bash
sudo apt-get install -y libasio-dev
```

## Compile the project

The script `build.sh` will build the project but if you want you may also want to add a `.env` file to define some cmake variables.

The current variables is:

```.env
VERSION=
BUILD_SSL=
BUILD_TESTS=
```

You can define more if needed. Pay attention if you want add a variable available into the project you should aslo update the `config.h.in` file.

## Run  the project

There is a `launch.json` defined you can modify and ajust.


### Enjoy the project! Contributions are welcome!