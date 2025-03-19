#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "filestream.h"
using std::string;
using std::endl;
using std::ios;

namespace filestream
{
    FileIO::FileIO()
    {
        fileStream.close();
        fileName = "default" + std::to_string(defaultCount) + ".txt"; // Create default .txt file
        defaultCount++;
    }

    FileIO::FileIO(const string& fileNameParam)
    {
        fileStream.close();
        fileName = fileNameParam;
        fileStream.open(fileName.c_str(), ios::in | ios::out | ios::app);
    }

    void FileIO::read(std::ostream& outputStream)
    {
        fileStream.close(); // Close and re-open file with ios::in flag
        fileStream.open(fileName.c_str(), ios::in | ios::app);
        fileStream.clear();
        fileStream.seekg(0); // set get-pointer to beginning of file
        string line;

        while (std::getline(fileStream, line))
        {
            outputStream << line << endl;
        }
    }

    void FileIO::write(const string& data)
    {
        fileStream.clear();

        // Read the current content of the file
        fileStream.seekg(0);
        std::stringstream buffer;
        buffer << fileStream.rdbuf(); // Store existing content in the buffer

        fileStream.close();

        // Open the file in write mode (truncating previous content)
        fileStream.open(fileName.c_str(), ios::out | ios::trunc);

        // Check if both "New Advice" and "Old Advice" are missing
        string content = buffer.str();
        size_t newAdvicePos = content.find("New Advice:");
        size_t oldAdvicePos = content.find("Old Advice:");

        // Write New Advice and Old Advice only once then append the previous content
        if (newAdvicePos == string::npos && oldAdvicePos == string::npos)
        {
            // if both are missing, write "New Advice:" and "Old Advice:"
            fileStream << "New Advice:" << endl;
            fileStream << data << endl;
            fileStream << "Old Advice:" << endl;
        }
        else
        {
            std::stringstream cleanedBuffer;
            string line;
            bool newAdviceWritten = false;
            bool oldAdviceWritten = false;

            // Copy everything except "New Advice" and "Old Advice"
            std::stringstream inputBuffer(content);
            while (std::getline(inputBuffer, line))
            {
                if (line == "New Advice:" && !newAdviceWritten)
                {
                    newAdviceWritten = true;
                    continue;
                }

                if (line == "Old Advice:" && !oldAdviceWritten)
                {
                    oldAdviceWritten = true;
                    continue;
                }

                cleanedBuffer << line << endl;
            }

            fileStream << "New Advice:" << endl;
            fileStream << data << endl;
            fileStream << "Old Advice:" << endl;

            fileStream << cleanedBuffer.str();
        }

        fileStream.flush();
    }

    void FileIO::writeAtEnd(const string& data)
    {
        fileStream.clear();

        // Open the file in append mode
        fileStream.open(fileName.c_str(), ios::out | ios::app);
        fileStream << data << endl;

        fileStream.flush();
    }

    FileIO::~FileIO()
    {
        if (fileStream.is_open())
        {
            fileStream.close();
        }
    }
};
