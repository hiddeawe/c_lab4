#include "time_of_day.h"

#include <iomanip>
#include <ostream>
#include <stdexcept>

namespace lab4 {

Time::Time() : Time(0, 0) {}

Time::Time(short hours) : Time(hours, 0) {}

Time::Time(short hours, short minutes) : hours_(0), minutes_(0) {
  set_hours(hours);
  set_minutes(minutes);
}

short Time::hours() const { return hours_; }

short Time::minutes() const { return minutes_; }

void Time::set_hours(short hours) {
  if (hours < 0 || hours >= kHoursPerDay) {
    throw std::out_of_range("Часы должны быть от 0 до 23");
  }
  hours_ = hours;
}

void Time::set_minutes(short minutes) {
  if (minutes < 0 || minutes >= kMinutesPerHour) {
    throw std::out_of_range("Минуты должны быть от 0 до 59");
  }
  minutes_ = minutes;
}

Time Time::Subtract(const Time& other) const {
  return FromMinutes(ToMinutes() - other.ToMinutes());
}

Time& Time::operator++() {
  *this = FromMinutes(ToMinutes() + 1);
  return *this;
}

Time Time::operator++(int) {
  Time previous = *this;
  ++(*this);
  return previous;
}

Time& Time::operator--() {
  *this = FromMinutes(ToMinutes() - 1);
  return *this;
}

Time Time::operator--(int) {
  Time previous = *this;
  --(*this);
  return previous;
}

Time::operator int() const { return ToMinutes(); }

Time::operator bool() const { return ToMinutes() != 0; }

bool Time::operator<(const Time& other) const {
  return ToMinutes() < other.ToMinutes();
}

bool Time::operator>(const Time& other) const {
  return ToMinutes() > other.ToMinutes();
}

Time Time::FromMinutes(int total_minutes) {
  const int normalized =
      (total_minutes % kMinutesPerDay + kMinutesPerDay) % kMinutesPerDay;
  return Time(static_cast<short>(normalized / kMinutesPerHour),
              static_cast<short>(normalized % kMinutesPerHour));
}

int Time::ToMinutes() const { return hours_ * kMinutesPerHour + minutes_; }

std::ostream& operator<<(std::ostream& stream, const Time& time) {
  const char previous_fill = stream.fill('0');
  stream << std::setw(2) << time.hours_ << ':' << std::setw(2)
         << time.minutes_;
  stream.fill(previous_fill);
  return stream;
}

} 
