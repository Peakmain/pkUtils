#include <chrono>
#include <ctime>
#include <vector>
#include <string>
#include <cmath>

// 日期模型 (对应 CalendarModel)
struct CalendarModel {
    int year;
    int month;
    int weekDay; // 0=周日,1=周一...6=周六
    int day;

    CalendarModel(int y, int m, int wd, int d)
            : year(y), month(m), weekDay(wd), day(d) {}
};

// 月份数据模型 (对应 Month)
struct Month {
    std::string headTitle;
    int month;
    std::vector<int> days;
    int year;
};

// 数据容器 (对应 MonthDataSource)
class MonthDataSource {
public:
    void pushData(const std::vector<Month>& months) {
        data_.insert(data_.end(), months.begin(), months.end());
    }

private:
    std::vector<Month> data_;
};

class CalendarUtils {
public:
    // 获取当前日期模型
    CalendarModel getCurrentDateModel() const {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::tm* now_tm = std::localtime(&t);

        return CalendarModel(
                now_tm->tm_year + 1900,
                now_tm->tm_mon + 1,
                now_tm->tm_wday,  // 周日=0, 周一=1...周六=6
                now_tm->tm_mday
        );
    }

    // 计算两个日期的天数差
    static int getDateDiff(const CalendarModel& start, const CalendarModel& end) {
        std::tm start_tm = {0};
        start_tm.tm_year = start.year - 1900;
        start_tm.tm_mon = start.month - 1;
        start_tm.tm_mday = start.day;

        std::tm end_tm = {0};
        end_tm.tm_year = end.year - 1900;
        end_tm.tm_mon = end.month - 1;
        end_tm.tm_mday = end.day;

        std::time_t start_time = std::mktime(&start_tm);
        std::time_t end_time = std::mktime(&end_tm);

        const double sec_per_day = 86400.0;
        return static_cast<int>(std::ceil(
                std::difftime(end_time, start_time) / sec_per_day
        ));
    }

    // 判断是否同一天
    bool isSameDay(const Month& month, int day, const CalendarModel& model) const {
        return (month.year == model.year) &&
                (month.month == model.month) &&
                (day == model.day);
    }

    // 判断是否为今天
    bool isToday(const CalendarModel& model) const {
        CalendarModel current = getCurrentDateModel();
        return (current.year == model.year) &&
                (current.month == model.month) &&
                (current.day == model.day);
    }

    // 获取明天日期模型
    CalendarModel getTomorrowDateModel() {
        auto now = std::chrono::system_clock::now();
        auto tomorrow = now + std::chrono::hours(24);
        std::time_t t = std::chrono::system_clock::to_time_t(tomorrow);
        std::tm* tm = std::localtime(&t);

        return CalendarModel(
                tm->tm_year + 1900,
                tm->tm_mon + 1,
                tm->tm_wday,
                tm->tm_mday
        );
    }

    // 生成月份日期数组
    std::vector<int> getMonthDate(int month, int year) const {
        std::vector<int> days;

        // 获取当月第一天星期和总天数
        std::tm first = {0};
        first.tm_year = year - 1900;
        first.tm_mon = month - 1;
        first.tm_mday = 1;
        std::mktime(&first);
        int firstWeekday = first.tm_wday;

        // 获取当月最后一天
        std::tm last = first;
        last.tm_mon = (month == 12) ? 0 : month;
        last.tm_mday = 0;  // 前一天是当月最后一天
        std::mktime(&last);
        int lastDay = last.tm_mday;
        int lastWeekday = last.tm_wday;

        // 填充前置空白
        days.insert(days.end(), firstWeekday, 0);

        // 填充当月日期
        for (int day = 1; day <= lastDay; ++day) {
            days.push_back(day);
        }

        // 填充后置空白
        int postEmpty = 6 - lastWeekday;
        if (postEmpty > 0) {
            days.insert(days.end(), postEmpty, 0);
        }

        return days;
    }

    // 比较日期先后
    bool isCalendarBefore(const CalendarModel& a, const CalendarModel& b) const {
        if (a.year != b.year) return a.year < b.year;
        if (a.month != b.month) return a.month < b.month;
        return a.day < b.day;
    }

    // 生成多个月份数据
    int getAllDate(int currentYear, int currentMonth,
            const CalendarModel& selectStartModel,
            MonthDataSource& output) {
        std::vector<Month> months;
        int initialIndex = 0;

        for (int i = 0; i <= 6; ++i) {
            int calcMonth = (currentMonth + i - 1) % 12 + 1;
            int calcYear = currentYear + (currentMonth + i - 1) / 12;

            std::vector<int> monthDays = getMonthDate(calcMonth, calcYear);

            char title[20];
            snprintf(title, sizeof(title), "%d年 %d月", calcYear, calcMonth);

            Month m = {
                    std::string(title),
                    calcMonth,
                    monthDays,
                    calcYear
            };

            months.push_back(m);

            if (selectStartModel.month == calcMonth) {
                initialIndex = i;
            }
        }

        output.pushData(months);
        return initialIndex;
    }
};
