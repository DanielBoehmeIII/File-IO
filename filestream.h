#ifndef FILESTREAM_H
#define FILESTREAM_H

#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::ostream;

namespace filestream
{
    class FileIO
    {
    public:
        // Default constructor
        FileIO();
        // Pre-condition: None
        // Post-condition: Initializes a FileIO object with a default file name and opens the file in append mode. If the file doesn't exist, it will be created.

        // Parameterized constructor
        FileIO(const string& fileNameParam);
        // Pre-condition: A valid file name (fileNameParam) is passed.
        // Post-condition: Initializes a FileIO object with the provided file name and opens the file in append mode. If the file doesn't exist, it will be created.

        // Destructor
        ~FileIO();
        // Pre-condition: FileIO object is being destroyed.
        // Post-condition: Closes the file if it is open.

        // Read function that reads the entire content of the file
        void read(ostream& outputStream);
        // Pre-condition: The file must exist and be open for reading.
        // Post-condition: The content of the file is written to the provided output stream.

        // Read function that reads a specific range of characters in the file
        void read(ostream& outputStream, int startChar, int endChar);
        // Pre-condition: The file must exist and be open for reading. The character range (startChar, endChar) must be valid.
        // Post-condition: The content from the specified character range is written to the provided output stream.

        // Read function that reads content from specific lines and words within those lines
        void read(ostream& outputStream, int startLine, int startWord, int endLine, int endWord);
        // Pre-condition: The file must exist and be open for reading. The provided line and word numbers must be valid.
        // Post-condition: The specified content from the file is written to the provided output stream.

        // Write function that writes data to the file
        void write(const string& data);
        // Pre-condition: The file must be open for writing. The data string is valid.
        // Post-condition: The provided data is written to the file.

        // Write function that writes data starting from a specific position
        void write(const string& data, int start);
        // Pre-condition: The file must be open for writing. The data string is valid, and the start position is within bounds.
        // Post-condition: The provided data is written to the file starting at the specified position.

        // Write function that appends data to the end of the file
        void writeAtEnd(const string& data);
        // Pre-condition: The file must be open for appending. The data string is valid.
        // Post-condition: The provided data is appended to the end of the file.

    private:
        std::fstream fileStream;
        string fileName;
        int defaultCount = 0;     // count for generating default file names
    };
}

#endif
