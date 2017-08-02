# Debugger Detection Proof-of-Concept

This application snippet attempts to load both dbghelp.dll and sbiedll.dll. If both modules are loaded into the same address space of your application then it is safe to assume your application is being debugged. However, if your application loads dbghelp.dll or sbiedll.dll by default this code snippet is not applicable.

## Getting Started

Make a pull request, download the file as a zip file, or copy the code from Main.c.

### Installing

This application is consoled based. Once compiled it can be ran via CMD.exe.

## Built With

* [Dev C++](https://sourceforge.net/projects/orwelldevcpp/)
* [Microsoft Windows API](https://msdn.microsoft.com/en-us/library/aa383723(VS.85).aspx)

## Authors

* **Mathew A. Stefanowich** - *Initial work*

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
