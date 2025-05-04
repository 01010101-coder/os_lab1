#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"

// Функция для вывода содержимого бинарного файла в консоль
void displayBinaryData(const std::string& filename) {
    std::ifstream inputFile(filename, std::ios::binary);
    employee emp;
    while (inputFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        std::cout << "Employee Number: " << emp.num << " Name: " << emp.name
                  << " Worked Hours: " << emp.hours << std::endl;
    }
}

// Функция для вывода содержимого отчетного файла в консоль
void showReportContent(const std::string& filename) {
    std::ifstream reportFile(filename);
    std::string line;
    while (std::getline(reportFile, line)) {
        std::cout << line << std::endl;
    }
}

int main() {
    std::string binaryFileName;
    int totalRecords = 0;

    std::cout << "Enter binary file name: ";
    std::cin >> binaryFileName;
    std::cout << "Enter number of records: ";
    std::cin >> totalRecords;

    // Формируем команду для запуска процесса Creator.exe
    std::string creatorCommand = "Creator.exe " + binaryFileName + " " + std::to_string(totalRecords);
    STARTUPINFO startupInfo = { sizeof(startupInfo) };
    PROCESS_INFORMATION processInfo;

    // Запускаем процесс Creator для создания бинарного файла
    if (!CreateProcess(NULL, const_cast<char*>(creatorCommand.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInfo)) {
        std::cerr << "Failed to start Creator process. Error: " << GetLastError() << std::endl;
        return 1;
    }
    // Ожидаем завершения процесса Creator
    WaitForSingleObject(processInfo.hProcess, INFINITE);
    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);

    // Выводим содержимое бинарного файла
    displayBinaryData(binaryFileName);

    std::string reportFile;
    double ratePerHour = 0;

    std::cout << "Enter report file name: ";
    std::cin >> reportFile;
    std::cout << "Enter hourly rate: ";
    std::cin >> ratePerHour;

    // Формируем команду для запуска процесса Reporter.exe
    std::string reporterCommand = "Reporter.exe " + binaryFileName + " " + reportFile + " " + std::to_string(ratePerHour);

    // Запускаем процесс Reporter для генерации отчета
    if (!CreateProcess(NULL, const_cast<char*>(reporterCommand.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInfo)) {
        std::cerr << "Failed to start Reporter process. Error: " << GetLastError() << std::endl;
        return 1;
    }
    // Ожидаем завершения процесса Reporter
    WaitForSingleObject(processInfo.hProcess, INFINITE);
    CloseHandle(processInfo.hProcess);
    CloseHandle(processInfo.hThread);

    // Выводим содержимое отчетного файла
    showReportContent(reportFile);
    return 0;
}
