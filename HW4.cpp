#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// Function to truncate long process names
string truncate(const string& str, size_t max_width) {
    if (str.length() > max_width) {
        return "..." + str.substr(str.length() - (max_width - 10));
    }
    return str;
}

void getTime() {
    time_t now = time(0);
    tm localtm;
    localtime_s(&localtm, &now);
    const char* daysOfWeek[] = { "Sun", "Mon", "Tue", "Wed", "Thurs", "Fri", "Sat" };
    const char* monthsName[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug",
    "Sep", "Oct", "Nov", "Dec"};


   cout << daysOfWeek[localtm.tm_wday] << " " << monthsName[localtm.tm_mon]
       << " " << localtm.tm_wday << " " << localtm.tm_hour << ":" << localtm.tm_min << ":"
       << localtm.tm_sec << " " << 1900 + localtm.tm_year << "\n";
}

// Function used to print a header
void printHeader() {
    getTime();
    cout << "+-------------------------------------+----------------------------+-------------------------+\n";
    cout << "| NVIDIA-SMI 551.86              Driver Version: 551.86             CUDA Version: 12.4       |\n";
    cout << "|-------------------------------------+----------------------------+-------------------------+\n";
    cout << "| GPU Name                  TCC/WDDM  | Bus-Id             Disp.A  |  Volatile Uncorr.   ECC |\n";
    cout << "| Fan Temp    Perf    Pwr: Usage/Cap  |              Memory-Usage  |  GPU-Util    Compute M. |\n";
    cout << "|=====================================+============================+=========================+\n";
    cout << "|   0 NVIDIA GeForce GTX 1080   WDDM  |       00000000:26:00.0 On  |                     N/A |\n";
    cout << "| 28%   37C   P8             11W/180W |          701MiB /  8192MiB |      0%         Default |\n";
    cout << "|                                     |                            |                     N/A |\n";
    cout << "+-------------------------------+----------------------+-------------------------------------+\n\n";
}

// Function used to print the process header
void printProcessHeader() {

    cout << "+--------------------------------------------------------------------------------------------+\n";
    cout << "| Processes:                                                                                 |\n";
    cout << "|  GPU   GI   CI          PID      Type       Process name                       GPU Memory  |\n";
    cout << "|        ID   ID                                                                 Usage       |\n";
    cout << "|============================================================================================+\n";
}

void printDummyProcesses() {
    cout << "|  " << setw(3) << left << 0
        << "   N/A  N/A        " << setw(9) << left << 1234
        << "  C+G       " << setw(36) << left << truncate("C:/Winder/dummy_process_1.exe", 35)
        << setw(13) << right << "N/A     |\n";

    cout << "|  " << setw(3) << left << 0
        << "   N/A  N/A        " << setw(9) << left << 3456
        << "  C+G       " << setw(36) << left << truncate("C:/Program Files/Some/Another/Very/Long/Path/long_dummy_process_2.exe", 35)
        << setw(13) << right << "N/A     |\n";

    cout << "|  " << setw(3) << left << 0
        << "   N/A  N/A        " << setw(9) << left << 8761
        << "  C+G       " << setw(36) << left << truncate("C:/Another/Directory/For/Processes/excessive_length_name_3.exe", 35)
        << setw(13) << right << "N/A     |\n";

    cout << "|  " << setw(3) << left << 0
        << "   N/A  N/A        " << setw(9) << left << 5431
        << "  C+G       " << setw(36) << left << truncate("C:/Another/Directory/For/Processes/dummy_background_task_4.exe", 35)
        << setw(13) << right << "N/A     |\n";

    cout << "|  " << setw(3) << left << 0
        << "   N/A  N/A        " << setw(9) << left << 1234
        << "  C+G       " << setw(36) << left << truncate("C:/Super/Duper/Long/Process/Directory/very_super_long_dummy_process_5.exe", 35)
        << setw(13) << right << "N/A     |\n";

    cout << "+--------------------------------------------------------------------------------------------+\n";

}

int main() {

    string command;

    while (true) {
        cout << "Enter command here: ";
        cin >> command;

            if (command == "nvidia-smi") {
                printHeader();
                printProcessHeader();
                printDummyProcesses();
                return 0;
            }
            else if (command == "exit") {
                return 1;
            }
            else {
                cout << "Command invalid!" << endl;
            }
    }

    return 0;
}
