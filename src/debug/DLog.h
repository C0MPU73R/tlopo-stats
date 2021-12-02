#ifndef DLOG_H
#define DLOG_H

#include <ofstream>
#include <iostream>

class DLog 
{
    public:
        explicit DLog ()
        {
        }

        // Overload << operator using log type
        template<typename T> 
        DLog& operator<< (const T& data) 
        {
            std::ofstream outfile;
            outfile.open("log.txt", ios_base::app);
            if (outfile.is_open()) {
                outfile << data << "\n";
            }
            outfile.close();
        }

        DLog (const DLog&) = delete;
        DLog &operator= (const DLog&) = delete;

    private:
        std::string filename;
};
#endif // !DLOG_H
