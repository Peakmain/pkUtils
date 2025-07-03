package com.peakmain.utils.calendar.model;

/**
 * author ：Peakmain
 * createTime：2025/7/3
 * mail:2726449200@qq.com
 * describe：
 */
public class CalendarModel {
   private int year;
    private int month;
    // 0=周日,1=周一...6=周六
    private int weekDay;
    private int day;

    public CalendarModel(int year, int month, int weekDay, int day) {
        this.year = year;
        this.month = month;
        this.weekDay = weekDay;
        this.day = day;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public int getWeekDay() {
        return weekDay;
    }

    public void setWeekDay(int weekDay) {
        this.weekDay = weekDay;
    }

    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        this.day = day;
    }

    @Override
    public String toString() {
        return "CalendarModel{" +
                "year=" + year +
                ", month=" + month +
                ", weekDay=" + weekDay +
                ", day=" + day +
                '}';
    }
}
