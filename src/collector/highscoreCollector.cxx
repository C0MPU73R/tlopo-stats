#include "highscoreCollector.h"

#include "report/highscoreReport.h"

HighscoreCollector::HighscoreCollector(const std::string& name, const std::string& event,
    Database* db, boost::asio::io_service& io_service) : StatCollectorBase(name, event, db)
{
    m_report = new HighscoreReport(name, db, io_service);
    m_reports.push_back(m_report);
}

HighscoreCollector::~HighscoreCollector()
{
}

void HighscoreCollector::callback(const Event& e)
{
    for (auto doId : e.doIds)
    {
        m_report->set(doId, e.value);
    }
}

std::string HighscoreCollector::get_type()
{
    return "highscore";
}
