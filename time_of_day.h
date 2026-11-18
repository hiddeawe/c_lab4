#ifndef LAB4_VARIANT7_TIME_OF_DAY_H_
#define LAB4_VARIANT7_TIME_OF_DAY_H_

#include <iosfwd>

namespace lab4 {

class Time {
 public:
  Time();
  explicit Time(short hours);
  Time(short hours, short minutes);

  short hours() const;
  short minutes() const;
  void set_hours(short hours);
  void set_minutes(short minutes);

  Time Subtract(const Time& other) const;

  Time& operator++();
  Time operator++(int);
  Time& operator--();
  Time operator--(int);

  operator int() const;
  explicit operator bool() const;

  bool operator<(const Time& other) const;
  bool operator>(const Time& other) const;

  friend std::ostream& operator<<(std::ostream& stream, const Time& time);

 private:
  static constexpr int kMinutesPerHour = 60;
  static constexpr int kHoursPerDay = 24;
  static constexpr int kMinutesPerDay = kMinutesPerHour * kHoursPerDay;

  static Time FromMinutes(int total_minutes);
  int ToMinutes() const;

  short hours_;
  short minutes_;
};

} 

#endif  
