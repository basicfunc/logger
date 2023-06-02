# logger - A simple logging library

The `logger` is a simple logging library written in C++ that provides an easy-to-use interface for logging messages in your applications. It aims to be platform-independent and does not rely on any external libraries.

## Features

The Logging Library currently provides the following features:

- **Basic Logging with Levels:** Log messages can be categorized into different levels such as `INFO`,` WARNING`, and `ERROR`, allowing you to control the verbosity of the logs while providing a convenient way to add log statements in your code.

- **Log Formatting:** Customize the format of log messages, allowing you to include timestamps, log levels, and additional contextual information in the log output.

- **Log to File:** Support writing log messages to a file in addition to printing them to the console. This allows for persistent logging and easier analysis of the logs over time.

- **Log Filtering:** Enable filtering of log messages based on their log levels, allowing you to control which log messages are displayed or saved based on their severity.

### Planned Features

The following features are planned to be added soon:

- **Exception Handling:** Enhance the library to catch and log exceptions automatically, providing valuable information for debugging and error analysis.

- **Thread Safety:** Ensure that the logging library is thread-safe, allowing multiple threads to log messages concurrently without conflicts or data corruption.

## Usage

To use the Logging Library in your project, follow these steps:

- Copy the `logger.h` and `logger.cpp` header file into your project's include directory and add `CMakeLists.txt` accordingly so that it can compile your project and link against the Library.

## License

The Logging Library is released under the [MIT License](LICENSE).

Feel free to contribute to the project by submitting bug reports, feature requests, or pull requests on GitHub.

