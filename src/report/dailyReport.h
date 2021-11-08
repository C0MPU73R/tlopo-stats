#ifndef DAILY_REPORT_H
#define DAILY_REPORT_H

#include "incrementalPeriodicReport.h"

class DailyReport : public IncrementalPeriodicReport 
{
    public:
        DailyReport(const std::string& name, Database* db,
                    boost::asio::io_service& io_service);
        virtual ~DailyReport();

    protected:
        virtual unsigned int time_until_next_task();
        virtual void calc_period_string();
};
#endif // !DAILY_REPORT_H
