# 42Cursus_CPP_Modules

This project is an integral part of the 42Lisboa curriculum and aims to develop multiple projects in C++ with the objective of learning about the language and the object-oriented paradigm.

## Modules

| Module | Content | Subject | Grade |
| --- | --- | --- | --- |
| [CPP_00](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/tree/main/CPP_00) | Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuf | [subject](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/blob/main/CPP_00/en.subject.pdf) | 100% |
| [CPP_01](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/tree/main/CPP_01) | Memory allocation, pointers to members, references, switch statement | [subject](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/blob/main/CPP_01/en.subject.pdf) | 100% |
| [CPP_02](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/tree/main/CPP_02) | Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form | [subject](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/blob/main/CPP_02/en.subject.pdf) | 100% |
| [CPP_03](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/tree/main/CPP_03) | Inheritance | [subject](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/blob/main/CPP_03/en.subject.pdf) | 100% |
| [CPP_04](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/tree/main/CPP_04) | Subtype polymorphism, abstract classes, interfaces | [subject](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/blob/main/CPP_04/en.subject.pdf) | 92% |
| [CPP_05](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/tree/main/CPP_05) | Try/Catch and Exceptions | [subject](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/blob/main/CPP_05/en.subject.pdf) | 100% |
| [CPP_06](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/tree/main/CPP_06) | C++ casts | [subject](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/blob/main/CPP_06/en.subject.pdf) | 100% |
| [CPP_07](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/tree/main/CPP_07) | C++ templates | [subject](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/blob/main/CPP_07/en.subject.pdf) | 80% |
| [CPP_08](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/tree/main/CPP_08) | Templated containers, iterators, algorithms | [subject](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/blob/main/CPP_08/en.subject.pdf) | 100% |
| [CPP_09](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/tree/main/CPP_09) | STL containers | [subject](https://github.com/Diogo13Antunes/42Cursus_CPP_Modules/blob/main/CPP_09/en.subject.pdf) | 100% |

## Installation / Usage

This project is designed to work on Linux and macOS.

Clone repo:
```shell
git clone https://github.com/dspereira/42Cursus-cpp-modules.git cpp_modules
```
Navigate to the folder of the module and exercise you have chosen. For example:
```shell
cd cpp_modules/module_00/ex00
```
Build:
```shell
make
```
Run the executable:
```shell
./megaphone
```

## Extra

To simplify the creation of a C++ module, I created a script called `create_setup.sh`. This script requires both the `create_setup.sh` script itself and the `base_setup_cpp` folder.

### Usage

```shell
./create_setup.sh [dir_name] [class_name]
```
