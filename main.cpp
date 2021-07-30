#include <iostream>
#include <boost/program_options.hpp>
#include <fstream>
#include "Person.h"


namespace po = boost::program_options;


void convert(const std::string& path)
{
    std::ifstream file(path);

    // Проверяем наличие файла
    if(!file.is_open())
    {
        throw std::runtime_error("file not found");
    }

    // Магия сортирует по именам в алфавитном порядке
    std::map<std::string, Person> personsMap;

    std::string str;

    int requestPerHour{};
    int hours;

    // Считываем файл построчно
    while(std::getline(file, str))
    {
        std::stringstream stream(str);
        std::string name;

        stream >> name;

        std::string word{};
        stream >> word;
        requestPerHour = std::stoi(word);

        stream >> word;
        hours = std::stoi(word);

        stream >> word;

        personsMap[name].additional =  word;

        personsMap[name].requestPerHour += requestPerHour;

        personsMap[name].totalRequest += requestPerHour * hours;

        personsMap[name].totalHours += hours;
    }

    file.close();

    std::ofstream outputFile("result_" + path);

    for(const auto& it : personsMap)
    {
        outputFile << it.first << " " << it.second.requestPerHour << " "
                << it.second.totalHours  << " " << it.second.totalRequest << " " << it.second.additional << std::endl;
    }

    outputFile.close();
}

int main(int argc, char* argv[])
try
{
    po::options_description options("General options");
    std::string path;
    options.add_options()("path", po::value<std::string>(&path), "file path");

    po::variables_map vm;

    try
    {
        po::parsed_options parsed = po::command_line_parser(argc, argv).options(options).allow_unregistered().run();
        po::store(parsed, vm);
        po::notify(vm);
        convert(path);
    }
    catch (std::exception& error)
    {
        std::cout << "Error " << error.what() << std::endl;
    }

    return 0;
}
catch (std::exception& error)
{
    std::cout << "Error " << error.what() << std::endl;
    return 1;
}
