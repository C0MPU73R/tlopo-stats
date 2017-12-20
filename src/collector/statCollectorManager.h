#pragma once

#include "database/database.h"
#include "database/cachedStatCollectorMap.h"

class StatCollectorManager final {
    public:
        void init(Database* db, boost::asio::io_service& io_service);

        bool add_incremental_collector(const std::string& name, const std::string& event);
        bool add_periodic_collector(const std::string& name, const std::string& event,
                                    unsigned int period);

        bool remove_collector(const std::string& name);

        inline void write_json(json_t** result)
        {
            m_collectors->write_json(result);
        }

        static StatCollectorManager* get_global_ptr()
        {
            static StatCollectorManager* mgr = new StatCollectorManager;
            return mgr;
        }

    private:
        StatCollectorManager();

        Database* m_db;
        boost::asio::io_service* m_io_service;

        CachedStatCollectorMap* m_collectors;

    friend class CachedStatCollectorMap;
};