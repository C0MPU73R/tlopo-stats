#pragma once

#include "report.h"
#include "stats_types.h"

#include <unordered_map>

class PeriodicReport : public Report {
    public:
        PeriodicReport(const std::string& name, unsigned int period,
                       boost::asio::io_service& io_service);
        virtual ~PeriodicReport();

        virtual void start();
        void set(doid_t key, int value);

    protected:
        void save_task(const boost::system::error_code& e);

        unsigned int m_period;
        std::unordered_map<doid_t, int> m_data;
};
