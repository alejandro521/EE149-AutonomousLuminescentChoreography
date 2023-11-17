# TemplaAutonomousLuminescentChoreography Franca RP2040 target platform
The goal of this project is to coordinate a sequence of movements wirelessly between a cluster of Pololu robots in order to make a lightshow. We will use HM-10 bluetooth modules to calculate the position and orientation of each robot. The Pololu robots will also communicate via bluetooth in order to follow directions from a master Pololu robot. The master Pololu is in charge of instructing other Pololus where to move next while also preventing collisions. 
This template is particularly well suited for the [LF Embedded Lab](https://www.lf-lang.org/lf-embedded-lab/) exercises.
Students should create a repository using this template and record their work within their repo.

The repo supports MacOS, Linux, and Windows through [WSL](https://learn.microsoft.com/en-us/windows/wsl/install).
To support RP2040-based boards, the repo uses the [Pico SDK](https://github.com/raspberrypi/pico-sdk/tree/master) as a submodule.
It also includes some code from the [pololu-3pi-2040-robot library](https://github.com/pololu/pololu-3pi-2040-robot/tree/master) by DavidEGrayson.

See the [getting started instructions](https://www.lf-lang.org/embedded-lab/GettingStarted.html) to get started.

## Emulator
To run basic tests and monitor GPIO, UART, and other supported peripherals, a [Node.js](https://nodejs.org/en)-based [emulator for the Raspberry Pi Pico](https://docs.wokwi.com/parts/wokwi-pi-pico) is provided in this repo. During the `nix` shell setup for the repo, the Node modules in the `test` directory are installed. This emulator is based on [Wokwi](https://wokwi.com).
Because it emulates the Pico board, not the Pololu robot, it will not be able to run all the programs for the robot.

By default, the emulator uses **hex** binaries which are generated by both build options. Any hex files that are in need of testing must be placed in the ``/test`` directory.

Run the following from the ``/test`` directory. It will run an emulator instance for each hex file in the directory in parallel and report results as plain text files in the same directory.

``` bash
cd test/
npm start
```

The text framework source code is available and can be easily extended. Currently, a test is set to report a **FAILING** status if it does not terminate within **10 seconds** but this callback condition is marked in ``run.ts`` and can be modified. To set a timeout in a LF program add the following
target property to the program header.

```
target C {
    ...
    timeout: 5 sec,
}
```

