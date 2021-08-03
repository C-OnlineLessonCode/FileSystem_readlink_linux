#include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <unistd.h>

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

        std::ofstream("/proc");

       const char* path;

        for(auto& p: fs::directory_iterator("/proc")){
            if(p.is_directory()) {
                path = (p.path()  / "exe").c_str();
                char  buf[500] = {};

                ssize_t res = readlink(path,  buf, sizeof(buf));
                if(res != -1) {

                    std::cout << p.path() <<" "<< buf <<'\n';
                }
            }
        }



    return a.exec();
}
