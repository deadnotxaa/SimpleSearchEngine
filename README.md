# SimpleSearchEngine

SimpleSearchEngine is a C++ application designed to index and search text documents. It leverages efficient data structures and algorithms to provide fast search capabilities through a command-line interface.

## Features
* Index text documents
* Perform search queries on indexed documents
* Fast and efficient search
* Modular and extensible design

## Project Structure

The project is organized as follows:

* ```bin/```: Main application source files.
  * ```index.cpp```: Code for indexing documents.
  * ```search.cpp```: Code for performing search queries.
* ```lib/```: Library source files.
  * ```Parser/```: Code for parsing input files and command-line arguments.
    * ```Parser.hpp```: Header file for the parser.
    * ```Parser.cpp```: Implementation file for the parser.
  * ```Search/```: Core search functionalities.
    * ```Search.hpp```: Header file for search functionalities.
    * ```Search.cpp```: Implementation file for search functionalities.
  * ```Index/```: Code for indexing documents.
    * ```Index.hpp```: Header file for the index.
    * ```Index.cpp```: Implementation file for the index.
* ```proto/```: Protocol buffers and related build files.
* ```CMakeLists.txt```: Build configuration file.

## Dependencies
**C++ Compiler:** Requires a C++20 compatible compiler.  
**Qt6**: For GUI components.  
**Google Protobuf**: For storing data.  

## Usage
After building project, start an ```./index``` exec file and you will see interface.

## Interface
<img width="580" alt="image" src="https://github.com/deadnotxaa/SimpleSearchEngine/assets/91655231/eb736d7d-cc4b-4a60-b14f-5c6f72fb893e">



