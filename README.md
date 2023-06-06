# logger - A simple logging library
![Build](https://github.com/basicfunc/logger/actions/workflows/cmake.yml/badge.svg)

The `logger` is a simple header only library written in C++ that provides an easy-to-use interface for logging messages in your applications. It aims to be platform-independent and does not rely on any external libraries.

## Features

The Logging Library currently provides the following features:

- **Logging Levels:** The Logger library supports three log levels: `INFO`, `WARN`, and `ERROR` to set the desired log level, and only messages with a level equal to or higher than the set level will be logged.

- **Customizable Formats:** User can customize the format of log messages and timestamps using placeholders. The library provides three default placeholders: `{timestamp}, {level}, and {message}`. These placeholders can be rearranged or combined with additional text to create the desired log message format.

- **Console Logging:** The Logger library logs messages to the console, allowing user to view the logs during application execution. Each log message is color-coded based on its log level to improve readability.

- **File Logging:** User can configure the library to log messages to a file. By specifying the log file's name, log messages can be appended to an existing file or create a new one. It will automatically close any previously opened log file before opening a new one. It also removes any ANSI escape codes from log message to ensure that the log file contains clean, readable text without any color formatting artifacts.

- **Timestamp Formatting:** The library supports customizable timestamp formats using the standard C++ syntax. User can define their preferred timestamp format, allowing them to include specific date and time information in log messages.

- **Streaming Interface:** The library provides a streaming interface for logging, allowing to use the `<<` operator conveniently.

### Planned Features

The following features are planned to be added soon:

- [ ] **More log levels:** Add `NONE`, `FATAL`, `DEBUG` and `VERBOSE` levels to have a broader range of options to categorize and prioritize log messages based on their significance and urgency.

- [ ] **Conditional Logging:** Adding the ability to conditionally log messages based on user-defined conditions. It will allow to specify criteria or rules under which a message should be logged or skipped.

- [ ] **Asynchronous Logging:** Implementing an asynchronous logging mechanism that offloads the logging process to a separate thread or a thread pool. Asynchronous logging can improve application performance by minimizing the impact of the logging operation on the main application thread.

- [ ] **Thread Safety:** Ensure that the logging library is thread-safe, allowing multiple threads to log messages concurrently without conflicts or data corruption.

- [ ] **Log Retention Policies:** Implement options to define log retention policies, such as maximum log file size or maximum log file age. This feature would automatically manage log files by rotating or archiving them based on predefined criteria, ensuring that logs are appropriately managed.

- [ ] **Log Event Hooks:** Provide hooks or callbacks that will allow to trigger custom actions when specific log events occur. This feature could be useful for scenarios such as sending notifications or performing additional processing when critical errors are logged.

## Usage

> ***Note***
> Don't copy the `CMakeLists.txt` from this repo.

To use this library, you need to include the `logger.h` header file in your C++ code, just grab it and put it in your source code tree.

Here are the features and usage instructions:

1. **Logger Initialization:**
   You can create an instance of the Logger class with optional parameters:
   ```cpp
   Logger logger(LogLevel level = INFO, const std::string &timestampFormat = "%Y-%m-%d %H:%M:%S", const std::string &messageFormat = "{timestamp} {level}: {message}");
   ```

2. **Setting Log Level:**
   You can set the log level to control the verbosity of the logs:
   ```cpp
   logger.setLogLevel(LogLevel level);
   ```
   Available log levels are `INFO`, `WARN`, and `ERROR`. The logger will only output messages with a log level equal to or higher than the set level.

3. **Setting Timestamp Format:**
   You can customize the format of the timestamp in the log messages:
   ```cpp
   logger.setTimestampFormat(const std::string &format);
   ```
   The format follows the rules of `strftime` function in C++. By default, the format is `%Y-%m-%d %H:%M:%S`.

4. **Setting Message Format:**
   You can customize the format of the log messages:
   ```cpp
   logger.setMessageFormat(const std::string &format);
   ```
   You can use the following placeholders in the format string:
   - `{timestamp}`: Replaced with the formatted timestamp.
   - `{level}`: Replaced with the log level (colored for readability in the console output).
   - `{message}`: Replaced with the actual log message.

5. **Logging Messages:**
   You can log messages with different log levels:
   ```cpp
   logger.log(LogLevel level, const std::string &message);
   ```
   Alternatively, there are specific methods for each log level:
   ```cpp
   logger.info(const std::string &message);
   logger.warn(const std::string &message);
   logger.error(const std::string &message);
   ```

6. **Logging with Stream-like Syntax:**
   You can log messages using a stream-like syntax:
   ```cpp
   logger << message;
   ```
   This syntax allows you to chain multiple messages together.

7. **Redirecting Logs to a File:**
   You can set a log file to which the logs will be written:
   ```cpp
   logger.setLogFile(const std::string &filename);
   ```
   The log file will be opened in append mode, and if an existing log file is already open, it will be closed first.

The Logger class outputs log messages to the console by default, and if a log file is specified, it will also write the messages to that file. The console output includes colored prefixes for each log level to enhance readability.

You can customize the log format, log level, and timestamp format according to your specific needs. The Logger class provides a flexible and convenient way to incorporate logging functionality into your C++ application.

## License

The Logging Library is released under the [MIT License](LICENSE).

Feel free to contribute to the project by submitting bug reports, feature requests, or pull requests.
