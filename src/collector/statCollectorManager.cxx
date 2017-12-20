#include "statCollectorManager.h"

#include "collector/statCollector.h"
#include "collector/incrementalStatCollector.h"
#include "globals.h"

StatCollectorManager::StatCollectorManager(Database* db, boost::asio::io_service& io_service) :
  m_db(db), m_io_service(io_service), m_collectors(this, COLLECTOR_MGR_CACHE_FILENAME)
{
}

bool StatCollectorManager::add_incremental_collector(const std::string& name,
                                                     const std::string& event)
{
    if (m_collectors.has_key(name))
        return false;

    auto collector = new IncrementalStatCollector(name, event, m_db, m_io_service);
    collector->start();
    m_collectors.set(name, collector);
    return true;
}

bool StatCollectorManager::add_periodic_collector(const std::string& name,
                                                  const std::string& event,
                                                  unsigned int period)
{
    if (m_collectors.has_key(name))
        return false;

    auto collector = new StatCollector(name, event, m_db, period, m_io_service);
    collector->start();
    m_collectors.set(name, collector);
    return true;
}

bool StatCollectorManager::remove_collector(const std::string& name)
{
    auto collector = m_collectors.get(name, nullptr);
    if (!collector)
        return false;

    m_collectors.erase(name);
    delete collector;
    return true;
}
